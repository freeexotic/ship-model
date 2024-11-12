#pragma once

#include "map_interface.h"

#include <QColor>

class QPainter;

class SceneObject : public QObject
{
    Q_OBJECT
public:
    SceneObject(QObject *parent = nullptr) ;
    virtual void paint(QPainter* painter);
};

