#include "math.h"
#include <cmath>
#include <algorithm>

double Math::abs(double value)
{
    return std::abs(value);
}

double Math::sign(double value)
{
    return value < 0.0 ? -1.0 : 1.0;
}

double Math::min(double lhs, double rhs)
{
    return std::min(lhs, rhs);
}

double Math::max(double lhs, double rhs)
{
    return std::max(lhs, rhs);
}

double Math::clamp(double min, double value, double max)
{
    return std::clamp(value, min, max);
}

double Math::sqrt(double value)
{
    return std::sqrt(value);
}

double Math::pow(double lhs, double rhs)
{
    return std::pow(lhs, rhs);
}

double Math::deg2rad(double a)
{
    return a * M_PI / 180.0;
}

double Math::rad2deg(double a)
{
    return a / M_PI * 180.0;
}

double Math::cos(double a)
{
    return std::cos(a);
}

double Math::sin(double a)
{
    return std::sin(a);
}

double Math::angle(double x, double y)
{
    return std::atan2(y, x);
}

double Math::hypot(double x, double y)
{
    return std::hypot(x, y);
}

double Math::heading(double a)
{
    a = std::fmod(a, 2.0 * M_PI);
    return a < 0.0 ? a + 2.0 * M_PI : a;
}

double Math::difference(double a)
{
    a = std::fmod(a + M_PI, 2.0 * M_PI);
    return a < 0.0 ? a + M_PI : a - M_PI;
}

double Math::traverse(double a)
{
    return a + M_PI_2;
}

double Math::reverse(double a)
{
    return a + M_PI;
}

double Math::atan(double a)
{
    return std::atan(a);
}

double Math::tan(double a)
{
    return std::tan(a);
}

// все предельно ясно

