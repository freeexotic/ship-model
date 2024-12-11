#include "boat_obj.h"
#include <QImage>

BoatObj::BoatObj(QObject* parent) : SceneObject(parent) {}

void BoatObj::paint(Orentation* orentation, QPainter* painter){
    if(img_mode()){
        imgPaint(orentation, painter);
    }
    else{
        polyPaint(orentation, painter);
    }
} // вся физика берется из boat_model

void BoatObj::imgPaint(Orentation* orentation, QPainter* painter) {
    const double B_rotation = rotation();
    Local2d B_position = position();

    QImage image = QImage("/home/freeexotic/Qt_project/Project/Boat/Texture/boat-2.png");
    QImage scaledImage = image.scaled(25, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    Local2d localImageCenter = B_position;
//Local2d(scaledImage.width()/2, scaledImage.height()/2);
    QPointF ScreenImageCenter = orentation->toQPoint(localImageCenter);

    painter->save();

    painter->translate(ScreenImageCenter);
    painter->scale(orentation->scale_, orentation->scale_);
    painter->rotate(orentation->rotation_ + Math::rad2deg(B_rotation));
    painter->translate(-ScreenImageCenter.x(), -ScreenImageCenter.y());
    painter->drawImage(orentation->toQPoint(B_position) - QPoint(scaledImage.width()/2, scaledImage.height()/2), scaledImage);
    painter->restore();
}

void BoatObj::polyPaint(Orentation* orentation, QPainter* painter){
    const double B_rotation = rotation();
    const Local2d B_position = position();

    QImage image = QImage("/home/freeexotic/Qt_project/Project/Boat/Texture/boat-2.png");
    QImage scaledImage = image.scaled(25, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    Local2d localImageCenter = Local2d(scaledImage.width()/2, scaledImage.height()/2);
    QPointF ScreenImageCenter = orentation->toQPoint(localImageCenter);

    painter->save();

    painter->translate(ScreenImageCenter);
    painter->scale(orentation->scale_, orentation->scale_);
    painter->rotate(orentation->rotation_ + Math::rad2deg(B_rotation));
    painter->translate(-ScreenImageCenter.x(), -ScreenImageCenter.y());
    painter->drawImage(orentation->toQPoint(B_position) - QPoint(scaledImage.width()/2, scaledImage.height()/2), scaledImage);
    painter->restore();
}
