#include "boat_obj.h"

BoatObj::BoatObj(QObject* parent) : SceneObject(parent) {}

void BoatObj::paint(Orentation* orentation, QPainter* painter){
    Q_UNUSED(orentation);
    Q_UNUSED(painter);
    QVector2D test = Position();
    test += Position();
} // вся физика берется из boat_model
