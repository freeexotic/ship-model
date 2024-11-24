#pragma once

#include "boat_obj.h"

#include<QPointF>


class BoatModel : public BoatObj
{
    Q_OBJECT

public:
    explicit BoatModel(QObject* parent = nullptr);

    Local2d position() override;
    double rotation() override;
    Local2d velocity() override;
    double anglvelocity() override;

    double length() override;
    double width() override;

    double engine1_trust() override;
    double engine2_trust() override;

    void set_engine1_trust(double trust_v) override;
    void set_engine2_trust(double trust_v) override;

    double rudder1Angle() override;
    double rudder2Angle() override;
private:
    void update_boat();

private:
    const double mass_; // масса
    const double inertion_; // момент инерции
    const double lenth_; // длина
    const double width_; // ширина
    const double w_hide_; // высота корабля под водой
    const double step_; // шаг обновления
    const double density_; // плотность водной среды
    const double WresistX_; // сопротивление воды по оси x
    const double WresistY_; // сопротивление воды по оси y
    const double WresistZ_; // сопротивление воды по оси z
    const double Xoffset_; // смещение двигателя по оси X
    const double Yoffset_; // смещение двигателя по оси Y
    const double maxRudderAngle_; // максимальный угол поворота корабля
    const double BoundForce_; // Максимальная скорость корабля

private:

    Local2d position_; // Экранный координаты корабля
    Local2d velocity_; // скорость корабля

    double rotation_; // угол показывающий куда повернуть корабль
    double anglVelocity_; // угловая скорость

    double engine1_trust_; // тяга двигателя 1
    double engine2_trust_; // тяга двигателя 2

    double rudder1Angle_; // угол руля 1
    double rudder2Angle_; // угол руля 2w2eqqzew


};


