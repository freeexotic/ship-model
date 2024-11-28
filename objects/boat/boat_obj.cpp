#include "boat_obj.h"

BoatObj::BoatObj(QObject* parent) : SceneObject(parent) {}

void BoatObj::paint(Orentation* orentation, QPainter* painter){
   // const double B_rotation = rotation();
  //  Q_UNUSED(B_rotation);

    QColor color_b = QColor(255,0,0);

   // Local2d position_b = position();

    painter->setPen(color_b);

    painter->drawEllipse(orentation->toQPoint(position()), 10, 10);
} // вся физика берется из boat_model
