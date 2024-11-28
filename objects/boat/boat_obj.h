#pragma once

#include <scene_object.h>
#include <QVector2D>

class BoatObj : public SceneObject
{
    Q_OBJECT
public:
    BoatObj(QObject* parent = nullptr);

    virtual Local2d position() const = 0;
    virtual double rotation() = 0;
    virtual Local2d velocity() = 0;
    virtual double anglvelocity() = 0;

    virtual double length() = 0;
    virtual double width() = 0;

    virtual double engine1_trust() = 0;
    virtual double engine2_trust() = 0;

    virtual void set_engine1_trust(double trust_v) = 0;
    virtual void set_engine2_trust(double trust_v) = 0;

    virtual double rudder1Angle() = 0;
    virtual double rudder2Angle() = 0;

private:
    void paint(Orentation* orentation, QPainter* painter) override;
};

