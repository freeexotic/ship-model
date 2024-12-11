#include "boat_model.h"
#include "polar_2d.h"
#include <QTimer>
#include <QDebug>
#include <QMutex>
#include <mutex>

BoatModel::BoatModel(bool img_mode, QObject* parent)
    : BoatObj(parent),
    mass_(0.5),
    inertion_(0.01),
    lenth_(0.6),
    width_(0.2),
    w_hide_(0.012), // высота корабля над уровнем воды
    step_(0.001),
    density_(1000),
    WresistX_(0.5),
    WresistY_(10),
    WresistZ_(0.03),
    Xoffset_(0.6),
    Yoffset_(0.2),
    maxRudderAngle_(Math::deg2rad(30)), // максимальный угол поворота корабля
    BoundForce_(100), // максимальная скорость корабля
    maxForce_(100),
    position_(Local2d(0,0)), // Экранный координаты корабля
    velocity_(0, 0), // скорость корабля
    rotation_(90), // угол показывающий куда повернуть корабль
    anglVelocity_(0), // угловая скорость
    engine1_trust_(1), // тяга двигателя 1
    engine2_trust_(1), // тяга двигателя 2
    rudder1Angle_(0.001), // угол руля 1
    rudder2Angle_(0.001), // угол руля 2
    img_mode_(img_mode) // Отрисовка корабля изображением или с помощью полигона
{ 
    const auto timer_updatepos = new QTimer(this);
    connect(timer_updatepos, &QTimer::timeout, this, &BoatModel::update_boat);
    timer_updatepos->start(1);
}


Local2d BoatModel::position()
{
    return position_;
}

double BoatModel::rotation(){
    return rotation_;
}

Local2d BoatModel::velocity(){
    return velocity_;
}

double BoatModel::anglvelocity(){
    return anglVelocity_;
}

double BoatModel::length(){
    return lenth_;
}

double BoatModel::width(){
    return width_;
}

double BoatModel::engine1_trust(){
    return engine1_trust_;
}

double BoatModel::engine2_trust(){
    return engine2_trust_;
}

double BoatModel::rudder1Angle(){
    return rudder1Angle_;
}


double BoatModel::rudder2Angle(){
    return rudder2Angle_;
}

void BoatModel::set_engine1_trust(double trust_v){
    engine1_trust_ = trust_v;
}

void BoatModel::set_engine2_trust(double trust_v){
    engine2_trust_ = trust_v;
}

bool BoatModel::img_mode() const{
    return img_mode_;
}

void BoatModel::update_boat(){
    std::unique_lock<std::mutex> lock(mutex, std::defer_lock);
    const Local2d ex = Polar2d(rotation_, 1).local(); // единичный вектора по оси x (по линии носа корабля)
    const Local2d ey = Polar2d(Math::traverse(rotation_), 1).local(); // единичный вектор перпендикулярный вектору ex

    const double velocityX = ex.dot(velocity_); // проекция скорости по X
    const double velocityY = ey.dot(velocity_); // проекция скорости на Y

    const double W_resist_F_X = WresistX_ * density_ * Math::pow(velocityX, 2) / 2 * w_hide_ * width_ * Math::sign(velocityX);
    // сопротивление воды по оси X
    const double W_resist_F_Y = WresistY_ * density_ * Math::pow(velocityX, 2) / 2 * w_hide_ * lenth_ * Math::sign(velocityY);
    // сопротивление воды по оси Y
    const double W_resist_F_Z = WresistZ_ * density_ * Math::pow(anglVelocity_, 2) / 2 * w_hide_ * lenth_ * Math::sign(anglVelocity_);
    // сопростивление по оси вращения
    const Local2d WaterF = ex * W_resist_F_X + ey * W_resist_F_Y;
    // Сила сопротивления воды
    const double ForceEfficacy = (BoundForce_ - velocityX) / BoundForce_;

    const double forceAngle1 = rotation_ - maxRudderAngle_ * rudder1Angle_ * (engine1_trust_ >= 0 ? 1.0 : 0.1 );
    // Влияние угла руля1 на поворот корабля (где последнее выражение учитывает в какую сторону работает двигатель1)
    const double forceAngle2 = rotation_ - maxRudderAngle_ * rudder2Angle_ * (engine2_trust_ >= 0 ? 1.0 : 0.1);
    // Влияние угла руля2 на поворот корабля (где последнее выражение учитывает в какую сторону работает двигатель2)

    const double forceEngine1 = engine1_trust_  * maxForce_ * ForceEfficacy;
    // Величина тяги первого двигателя
    const double forceEngine2 = engine2_trust_ * maxForce_ * ForceEfficacy;
    // Величина тяги второго двигателя

    const Local2d force1 = Polar2d(forceAngle1, forceEngine1).local();
    // Cила 1 двигателя
    const Local2d force2 = Polar2d(forceAngle2, forceEngine2).local();
    // Сила 2 двигателя

    const Local2d enginLocationX = -ex * Xoffset_ - ey * Yoffset_;
    const Local2d enginLocationY = -ex * Xoffset_ + ey * Yoffset_;
    // смещение двигателей относительно центра масс

    const Local2d Environmental_impact = Local2d();
    // Тут можно задать внешнее воздействие например силу ветра или течение

    const Local2d F_total = force1 + force2 - WaterF + Environmental_impact;
    // общая сила
    const double momentF = enginLocationX.cross(force1) + enginLocationY.cross(force2) - W_resist_F_Z;
    // момент силы

    velocity_ += F_total / mass_ * step_;
    // Закон времени : скорость равна Сила/массу * время + старая скорость

    anglVelocity_ += momentF / inertion_ * step_;
    // Изменение угловой скорости
    lock.lock();
    position_ += velocity_ * step_;
    //изменение позиции корабля
    rotation_ += anglVelocity_ * step_;
    //изменение угла корабля
    lock.unlock();

    changed();
}












