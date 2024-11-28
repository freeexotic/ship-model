#pragma once

#include "local_2d.h"
#include "math.h"
#include <QTransform> // для матричных преобразований

class Orentation
{
public:
    Orentation(const Local2d& origin = Local2d(),
               const QPointF& start = QPointF(),
               int rotation = 0 ,
               int zoom = 0);

    QPointF toQPoint (const Local2d& point); // преобразование к экранным координатам
    Local2d toLocal (const QPointF& point); // преобразование к локальным координатам
    double scale_;
    double rotation_;

private:
    QTransform to_;
    QTransform from_;
};


