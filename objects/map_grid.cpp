#include "map_grid.h"
#include <QPainter>
#include <QFontDatabase>


MapGrid::MapGrid(const int shape,const QColor color, QObject *parent) : SceneObject(parent),
    _GridShape(shape),
    _color(color)
{
}


void MapGrid::paint(Orentation* orentation, QPainter* painter){
    painter->setBrush(Qt::NoBrush);

    int segment_lenth = 80;

    int size = segment_lenth * _GridShape;

    QColor color = _color;

    if (_GridShape>0){
        color.setAlpha(20);
        painter->setPen(color);
        for(int i = -size; i<=size; i++){
            if(i%segment_lenth != 0 && i%_GridShape==0){
                DrawLine(orentation, painter,size, i);
            }
        }
    }
    // отрисовка тоникх линий сцены

    if (_GridShape>0){
        color.setAlpha(64);
        painter->setPen(color);
        for(int i = -size; i <= size ; i++){
            if(i%segment_lenth == 0 || i ==0 || i == size){
                DrawLine(orentation, painter,size, i);
            }
        }
    }
    // отрисовка толстых линий сцены
}




void MapGrid::DrawLine(Orentation* orentation, QPainter* painter, const int size, const int i){
    const auto p1 = orentation->toQPoint(1.0 * Local2d(i, size)).toPoint();
    const auto p2 = orentation->toQPoint(1.0 * Local2d(i, -size)).toPoint();
    const auto p3 = orentation->toQPoint(1.0 * Local2d(size, i)).toPoint();
    const auto p4 = orentation->toQPoint(1.0 * Local2d(-size, i)).toPoint();
    painter->drawLine(p1, p2);
    painter->drawLine(p3, p4);
}

// Отрисовка линий
// toPoint() - перевод из QPointF в QPoint


