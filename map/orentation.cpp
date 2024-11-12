#include "orentation.h"

Orentation::Orentation(const Local2d& origin,
                       const QPointF& start,
                       int rotation,
                       int zoom)
{
    const int dpm = 25;

    const double scale = dpm * Math::pow(1.01, zoom/8.0);

    to_.translate(start.x(), start.y()); // перемещение к точке отсчета
    to_.scale(scale, scale); // скалирование
    to_.rotate(rotation); // поворот
    to_.translate(-origin.x(), -origin.y()); // возвращение к изначальной точке

    from_ = to_.inverted(); // создание обратной матрицы для преобразования экранных координат к локальным координатам

    scale_ = Math::sqrt(to_.determinant()); // вычисление скалирования
}

QPointF Orentation::toQPoint(const Local2d& point_)
{
    QPointF point = QPointF(point_.x(), point_.y());
    return to_.map(point);
}
// из локальной координаты в экранную

Local2d Orentation::toLocal(const QPointF& point_){
    QPointF point = from_.map(point_);
    return Local2d(point.x(), point.y());
}
// из экранной координаты в локальную
