#include "math.h"
#include "local_2d.h"
#include "polar_2d.h"

Local2d::Local2d(double x, double y)
    : _x(x)
    , _y(y)
{
}
// база

double Local2d::x() const
{
    return _x;
}
// база
double Local2d::y() const
{
    return _y;
}
// база
double Local2d::a() const
{
    return Math::angle(_x, _y);
}
// база
double Local2d::r() const
{
    return Math::hypot(_x, _y);
}

Polar2d Local2d::polar() const
{
    return Polar2d(a(), r());
}
// from local to polar
Polar2d Local2d::direct(double r) const
{
    return Polar2d(a(), r);
}

// определение расстояния ???

Polar2d Local2d::normal(double r) const
{
    return Polar2d(Math::traverse(a()), r);
}

// нормаль

Polar2d Local2d::transition(const Local2d& rhs) const
{
    const auto delta = rhs - *this;
    return Polar2d(delta.a(), delta.r());
}
// направление по local2d

Local2d Local2d::transit(const Polar2d& transition) const
{
    const auto delta = Local2d(transition.x(), transition.y());
    return *this + delta;
}

Local2d Local2d::project(const Local2d& begin, const Local2d& end) const
{
    const auto u = end - begin;
    const auto v = *this - begin;
    const auto lambda = Math::clamp(0.0, v.dot(u) / u.dot(u), 1.0);
    return begin + lambda * u;
}

double Local2d::dot(const Local2d& rhs) const
{
    return _x * rhs._x + _y * rhs._y;
}

double Local2d::cross(const Local2d& rhs) const
{
    return _x * rhs._y - _y * rhs._x;
}

Local2d Local2d::operator +() const
{
    return *this;
}

Local2d Local2d::operator -() const
{
    return Local2d(-_x, -_y);
}

Local2d& Local2d::operator +=(const Local2d& rhs)
{
    _x += rhs._x;
    _y += rhs._y;
    return *this;
}

Local2d Local2d::operator +(const Local2d& rhs) const
{
    return Local2d(*this) += rhs;
}

Local2d& Local2d::operator -=(const Local2d& rhs)
{
    _x -= rhs._x;
    _y -= rhs._y;
    return *this;
}

Local2d Local2d::operator -(const Local2d& rhs) const
{
    return Local2d(*this) -= rhs;
}

Local2d& Local2d::operator *=(double rhs)
{
    _x *= rhs;
    _y *= rhs;
    return *this;
}

Local2d Local2d::operator *(double rhs) const
{
    return Local2d(*this) *= rhs;
}

Local2d& Local2d::operator /=(double rhs)
{
    _x /= rhs;
    _y /= rhs;
    return *this;
}

Local2d Local2d::operator /(double rhs) const
{
    return Local2d(*this) /= rhs;
}

Local2d operator *(double lhs, const Local2d& rhs)
{
    return rhs * lhs;
}

QDebug operator <<(QDebug debug, const Local2d& rhs)
{
    QDebugStateSaver saver(debug);
    debug.nospace().noquote() << "L(" << rhs.x() << ", " << rhs.y() << ")";
    return debug;
}
