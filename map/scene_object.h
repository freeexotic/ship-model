#pragma once

#include "map_interface.h"
#include "orentation.h"


#include <QColor>

class QPainter;

class SceneObject : public QObject
{
    Q_OBJECT
public:
    explicit SceneObject(QObject *parent = nullptr) ;
    virtual void paint(Orentation* orentation, QPainter* painter);

    virtual void move(Orentation* orentation, const QPointF& point);
    virtual bool press(Orentation* orentation, const QPointF& point);
    virtual void release(Orentation* orentation, const QPointF& point);

    Q_SIGNAL void changed();
};

