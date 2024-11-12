#include "math.h"
#include "local_2d.h"
#include "polar_2d.h"

Polar2d::Polar2d(double a, double r)
    : _a(a)
    , _r(r)
{
}
// оперделение Polar2d
double Polar2d::a() const
{
    return _a;
}
// возвращение угла

double Polar2d::r() const
{
    return _r;
}
// возвращение радиуса

double Polar2d::x() const
{
    return Math::cos(_a) * _r;
}
// возвращение X

double Polar2d::y() const
{
    return Math::sin(_a) * _r;
}
// возвращение Y

Local2d Polar2d::local() const
{
    return Local2d(x(), y());
}
// from Polar2d to Local2d

Polar2d Polar2d::direct(double r) const
{
    return Polar2d(_a, r);
}

// возвращение направления ?????

Polar2d Polar2d::normal(double r) const
{
    return Polar2d(Math::traverse(_a), r);
}
// определение нормали

Polar2d Polar2d::canonical() const
{
    return Polar2d(Math::heading(_r < 0.0 ? Math::reverse(_a) : _a), _r < 0.0 ? -_r : _r);
}

// ??

Polar2d Polar2d::operator +() const
{
    return *this;
}
// Доделать ??

Polar2d Polar2d::operator -() const
{
    return Polar2d(_a, -_r);
}
// Доделать ??

Polar2d& Polar2d::operator *=(double rhs)
{
    _r *= rhs;
    return *this;
}

// умножение координат

Polar2d Polar2d::operator *(double rhs) const
{
    return Polar2d(*this) *= rhs;
}

// умножение координат

Polar2d& Polar2d::operator /=(double rhs)
{
    _r /= rhs;
    return *this;
}

// деление координат

Polar2d Polar2d::operator /(double rhs) const
{
    return Polar2d(*this) /= rhs;
}

// деление координат

Polar2d operator *(double lhs, const Polar2d& rhs)
{
    return rhs * lhs;
}

//перемножение координат

QDebug operator <<(QDebug debug, const Polar2d& rhs)
{
    QDebugStateSaver saver(debug);
    debug.nospace().noquote() << "P(" << rhs.a() << ", " << rhs.r() << ")";
    return debug;
}

// вывод координат
