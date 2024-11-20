#pragma once

#include "boat_obj.h"

#include<QPointF>
#include <QVector2D>


class BoatModel : public BoatObj
{
    Q_OBJECT

public:
    explicit BoatModel(QObject* parent = nullptr);

    QVector2D Position() override;
    QVector2D Rotation() override;
private:
    double mass_;
    double lenth_;
    double width_;

    QVector2D position_; // Экранный координаты корабля
    QVector2D velocity_; // скорость корабля

    QVector2D rotation_; // угол показывающий куда повернуть корабль
    QVector2D anglVelocity_; // угловая скорость

    double engine1_trust_; // тяга двигателя 1
    double engine2_trust_; // тяга двигателя 2

    double rudder1Angle_; // угол руля 1
    double rudder2Angle_; // угол руля 2w2eqqzew

};


