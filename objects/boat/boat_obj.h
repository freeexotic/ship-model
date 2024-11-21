#pragma once

#include <scene_object.h>
#include <QVector2D>

class BoatObj : public SceneObject
{
    Q_OBJECT
public:
    BoatObj(QObject* parent = nullptr);

    void paint(Orentation* orentation, QPainter* painter) override;

    virtual Local2d position() = 0;
    virtual double rotation() = 0;
    virtual Local2d velocity() = 0;
    virtual Local2d anglvelocity() = 0;

    virtual double length() = 0;
    virtual double width() = 0;

    virtual double engine1_trust() = 0;
    virtual double engine2_trust() = 0;

    virtual void set_engine1_trust(double trust_v) = 0;
    virtual void set_engine2_trust(double trust_v) = 0;

    virtual double rudder1Angle() = 0;
    virtual double rudder2Angle() = 0;

};

