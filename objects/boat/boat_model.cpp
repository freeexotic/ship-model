#include "boat_model.h"


BoatModel::BoatModel(QObject* parent)
    : BoatObj(parent),
    mass_(1.0),
    lenth_(2.0),
    width_(1.0),
    position_(QVector2D(0,0)),// Экранный координаты корабля
    velocity_(QVector2D(0,0)), // скорость корабля
    rotation_(QVector2D(0,0)), // угол показывающий куда повернуть корабль
    anglVelocity_(QVector2D(0,0)), // угловая скорость
    engine1_trust_(0), // тяга двигателя 1
    engine2_trust_(0), // тяга двигателя 2
    rudder1Angle_(0), // угол руля 1
    rudder2Angle_(0) // угол руля 2
{}

QVector2D BoatModel::Position(){
    return position_;
}

QVector2D BoatModel::Rotation(){
    return rotation_;
}
