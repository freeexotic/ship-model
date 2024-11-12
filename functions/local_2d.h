#pragma once

#include <QDebug>

class Polar2d;

class Local2d
{
public:
    explicit Local2d(double x = 0.0, double y = 0.0);

    double x() const;
    double y() const;

    double a() const;
    double r() const;

    Polar2d polar() const;

    Polar2d direct(double r = 1.0) const;
    Polar2d normal(double r = 1.0) const;

    Polar2d transition(const Local2d& rhs) const;
    Local2d transit(const Polar2d& transition) const;

    Local2d project(const Local2d& begin, const Local2d& end) const;

    double dot(const Local2d& rhs) const;
    double cross(const Local2d& rhs) const;

    Local2d operator +() const;
    Local2d operator -() const;

    Local2d& operator +=(const Local2d& rhs);
    Local2d operator +(const Local2d& rhs) const;

    Local2d& operator -=(const Local2d& rhs);
    Local2d operator -(const Local2d& rhs) const;

    Local2d& operator *=(double rhs);
    Local2d operator *(double rhs) const;

    Local2d& operator /=(double rhs);
    Local2d operator /(double rhs) const;

private:
    double _x;
    double _y;
};

Local2d operator *(double lhs, const Local2d& rhs);

QDebug operator <<(QDebug debug, const Local2d& rhs);
