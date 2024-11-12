#pragma once

#include "scene_object.h"
#include <QObject>

class MapGrid : public SceneObject
{
    Q_OBJECT
public:
    explicit MapGrid(int shape, QColor color, QObject* parent = nullptr);
    void paint(QPainter* painter) override;


private:
 //   void DrawGrid(QPainter* painter);

    void DrawLine(QPainter* painter, const int size, const int i);

    const int _GridShape;
    const QColor _color;
};
