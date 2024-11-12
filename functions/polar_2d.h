#pragma once

#include <QDebug>

class Local2d;

class Polar2d
{
public:
    explicit Polar2d(double a = 0.0, double r = 0.0);

    double a() const;
    double r() const;

    double x() const;
    double y() const;

    Local2d local() const;

    Polar2d direct(double r = 1.0) const;
    Polar2d normal(double r = 1.0) const;

    Polar2d canonical() const;

    Polar2d operator +() const;
    Polar2d operator -() const;

    Polar2d& operator *=(double rhs);
    Polar2d operator *(double rhs) const;

    Polar2d& operator /=(double rhs);
    Polar2d operator /(double rhs) const;

private:
    double _a;
    double _r;
};

Polar2d operator *(double lhs, const Polar2d& rhs);

QDebug operator <<(QDebug debug, const Polar2d& rhs);
