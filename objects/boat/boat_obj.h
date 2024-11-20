#pragma once

#include <scene_object.h>
#include <QVector2D>

class BoatObj : public SceneObject
{
    Q_OBJECT
public:
    BoatObj(QObject* parent = nullptr);

    void paint(Orentation* orentation, QPainter* painter) override;

    virtual QVector2D Position() = 0;
    virtual QVector2D Rotation() = 0;
};

