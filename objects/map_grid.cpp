#include "map_grid.h"
#include <QPainter>
#include <QFontDatabase>


MapGrid::MapGrid(const int shape,const QColor color, QObject *parent) : SceneObject(parent),
    _GridShape(shape),
    _color(color)
{
}


void MapGrid::paint(QPainter* painter){
    painter->setBrush(Qt::NoBrush);

    int segment_lenth = 80;

    int size = segment_lenth * _GridShape;

    QColor color = _color;

    if (_GridShape>0){
        color.setAlpha(20);
        painter->setPen(color);
        for(int i = 0; i!=size; i++){
            if(i%segment_lenth != 0 && i%_GridShape==0){
                DrawLine(painter,size, i);
            }
        }
    }

    if (_GridShape>0){
        color.setAlpha(64);
        painter->setPen(color);
        for(int i = 0; i != size ; i++){
            if(i%segment_lenth == 0 || i ==0 || i == size){
                DrawLine(painter,size, i);
            }
        }
    }
}




void MapGrid::DrawLine(QPainter* painter, const int size, const int i){
    const QPointF p1 = QPointF(i, size);
    const QPointF p2 = QPointF(i, 0);
    const QPointF p3 = QPointF(0, i);
    const QPointF p4 = QPointF(size, i);

    painter->drawLine(p1,p2);
    painter->drawLine(p3,p4);
}




