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


private:
    QList<std::shared_ptr<SceneObject>> _objects;
    Orentation orentation;

    void resetting();

};


