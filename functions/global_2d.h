#pragma once

#include <QDebug>

class Polar2d;

class Global2d
{
public:
    explicit Global2d(double latitude = 0.0, double longitude = 0.0);

    double latitude() const;
    double longitude() const;

    Polar2d transition(const Global2d& rhs) const;
    Global2d transit(const Polar2d& transition) const;

private:
    double _latitude;
    double _longitude;
};

QDebug operator <<(QDebug debug, const Global2d& rhs);
