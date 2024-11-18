#pragma once

#include <QWidget>
#include <QPainter>
#include <QObject>
#include <QMouseEvent>
#include <memory>

#include <QPaintEvent>
#include <QFontDatabase>

#include "scene_object.h"
#include "orentation.h"

class SceneObject;

class MapInterface : public QWidget
{
    Q_OBJECT
public:
    MapInterface(QWidget* parent = nullptr);
    void AppendObject(const std::shared_ptr<SceneObject> object);
    void PrintObject();
    void paintEvent(QPaintEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* const event);
    void wheelEvent(QWheelEvent* const event);
    void mousePressEvent(QMouseEvent* const event);

private:
    QList<std::shared_ptr<SceneObject>> _objects;
    Orentation orentation_;

    void resetting();

    double zoom_;
    double rotation_;

    QPointF toehold;
    Local2d start_p;
};


