#include "boat_model.h"
#include "polar_2d.h"

BoatModel::BoatModel(QObject* parent)
    : BoatObj(parent),
    mass_(1.0),
    lenth_(2.0),
    width_(1.0),
    step_(0.0001),
    density_(1000),
    position_(Local2d(0,0)),// Экранный координаты корабля
    velocity_(Local2d(0,0)), // скорость корабля
    rotation_(0), // угол показывающий куда повернуть корабль
    anglVelocity_(Local2d(0,0)), // угловая скорость
    engine1_trust_(0), // тяга двигателя 1
    engine2_trust_(0), // тяга двигателя 2
    rudder1Angle_(0), // угол руля 1
    rudder2Angle_(0) // угол руля 2
{}

Local2d BoatModel::position(){
    return position_;
}

double BoatModel::rotation(){
    return rotation_;
}

Local2d BoatModel::velocity(){
    return velocity_;
}

Local2d BoatModel::anglvelocity(){
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

void BoatModel::update_boat(){
    const Local2d ex = Polar2d(rotation_, 1).local(); // единичный вектора по оси x (по линии носа корабля)
    const Local2d ey = Polar2d(Math::traverse(rotation_), 1).local(); // единичный вектор перпендикулярный вектору ex

    const double velocityX = ex.dot(velocity_);
    const double velocityY = ey.dot(velocity_);

    Q_UNUSED(velocityX);
    Q_UNUSED(velocityY);
}













