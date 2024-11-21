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
    Local2d anglvelocity() override;

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
    double mass_; // масса
    double lenth_; // длина
    double width_; // ширина
    double step_; // шаг обновления
    double density_; // плотность водной среды

    Local2d position_; // Экранный координаты корабля
    Local2d velocity_; // скорость корабля

    double rotation_; // угол показывающий куда повернуть корабль
    Local2d anglVelocity_; // угловая скорость

    double engine1_trust_; // тяга двигателя 1
    double engine2_trust_; // тяга двигателя 2

    double rudder1Angle_; // угол руля 1
    double rudder2Angle_; // угол руля 2w2eqqzew

};


