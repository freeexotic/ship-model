#include "scene_object.h"


SceneObject::SceneObject(QObject* parent) : QObject(parent) {}

void SceneObject::paint(QPainter* painter){
    Q_UNUSED(painter);
}

