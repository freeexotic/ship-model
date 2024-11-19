#include "math.h"
#include "global_2d.h"
#include "polar_2d.h"

#include <GeographicLib/Rhumb.hpp>

Global2d::Global2d(double latitude, double longitude)
    : _latitude(latitude)
    , _longitude(longitude)
{
}
// задание Global2d

double Global2d::longitude() const
{
    return _longitude;
}
// longitude - долгота

double Global2d::latitude() const
{
    return _latitude;
}
// latitide - ширина

Polar2d Global2d::transition(const Global2d& rhs) const
{
    double s12, azi1, azi2;
    const auto& wgs = GeographicLib::Rhumb::WGS84();
    wgs.Inverse(_latitude, _longitude, rhs.latitude(), rhs.longitude(), s12, azi1, azi2);
    return Polar2d(Math::deg2rad(azi1), s12);
}
// Оперделяет азимут и расстояние между 1 и 2 точкой (возвращает Polar2d)

Global2d Global2d::transit(const Polar2d& transition) const
{
    double lat2, lon2;
    const auto azi1 = Math::rad2deg(transition.a());
    const auto s12 = transition.r();
    const auto& wgs = GeographicLib::Rhumb::WGS84();
    wgs.Direct(_latitude, _longitude, azi1, s12, lat2, lon2);
    return Global2d(lat2, lon2);

}
// определяет новую точку Global2d исходя из Polar2d

QDebug operator <<(QDebug debug, const Global2d& rhs)
{
    QDebugStateSaver saver(debug);
    debug.nospace().noquote() << "G(" << rhs.latitude() << ", " << rhs.longitude() << ")";
    return debug;
}

// Вывод Global2d
