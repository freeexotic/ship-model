#pragma once

#include "scene_object.h"
#include <QObject>

class MapGrid : public SceneObject
{
    Q_OBJECT
public:
    explicit MapGrid(int shape, QColor color, QObject* parent = nullptr);
    void paint(Orentation* orentation, QPainter* painter) override;



private:

    void DrawLine(Orentation* orentation, QPainter* painter, const int size, const int i);

    const int _GridShape;
    const QColor _color;
};
