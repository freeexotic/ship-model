#include "map_interface.h"

MapInterface::MapInterface(QWidget* parent) : QWidget(parent) {

}

void MapInterface::AppendObject(std::shared_ptr<SceneObject> object){
    _objects.append(object);
}

void MapInterface::paintEvent(QPaintEvent* const event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(0.5, 0.5);
    painter.setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));

    for(auto obj : _objects){
        painter.save();
        obj->paint(&painter);
        painter.restore();
    }
    // paintEvent переопределяет метод в классе QWidget
    event->accept(); // сигнализирует фреймворку Qt, что событие было обработано текущим объектом и дальнейшее распространение события не требуется
}

void MapInterface::mouseMoveEvent(QMouseEvent* event)
{
    if (cursor() == Qt::PointingHandCursor)
    {
        for (auto object: _objects)
            object->move(&_plane, event->pos());

        update();
    }

    if (cursor() == Qt::OpenHandCursor)
    {
        _pivot = event->pos();
        refresh();
    }

    event->accept();
}

void MapInterface::resetting(){

}

