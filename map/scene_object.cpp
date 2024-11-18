#include "scene_object.h"


SceneObject::SceneObject(QObject* parent) : QObject(parent) {}

void SceneObject::paint(Orentation* orentation, QPainter* painter){
    Q_UNUSED(painter);
    Q_UNUSED(orentation);
}

void SceneObject::move(Orentation* orentation, const QPointF& point){
    Q_UNUSED(orentation);
    Q_UNUSED(point);
}

bool SceneObject::press(Orentation* plane, const QPointF& point)
{
    Q_UNUSED(plane)
    Q_UNUSED(point)
    return false;
}

void SceneObject::release(Orentation* plane, const QPointF& point){
    Q_UNUSED(plane);
    Q_UNUSED(point);
}

