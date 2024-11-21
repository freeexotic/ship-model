#include "boat_obj.h"

BoatObj::BoatObj(QObject* parent) : SceneObject(parent) {}

void BoatObj::paint(Orentation* orentation, QPainter* painter){
    Q_UNUSED(orentation);
    Q_UNUSED(painter);
} // вся физика берется из boat_model
