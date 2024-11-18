#include "map_interface.h"

MapInterface::MapInterface(QWidget* parent) :
    QWidget(parent),
    zoom_(0),
    rotation_(0)
{
    setFocusPolicy(Qt::WheelFocus);
    setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
}

void MapInterface::AppendObject(std::shared_ptr<SceneObject> object){
    _objects.append(object);
}

void MapInterface::paintEvent(QPaintEvent* const event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(0.5, 0.5);
    painter.setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));

    for(const auto& obj : _objects){
        painter.save();
        obj->paint(&orentation_, &painter);
        painter.restore();
    }
    // paintEvent переопределяет метод в классе QWidget
    event->accept(); // сигнализирует фреймворку Qt, что событие было обработано текущим объектом и дальнейшее распространение события не требуется
}


void MapInterface::mouseMoveEvent(QMouseEvent* event) //ok
{
    if (cursor() == Qt::PointingHandCursor)
    {
        for (auto object: _objects)
            object->move(&orentation_, event->pos());

        update();
    }

    if (cursor() == Qt::OpenHandCursor)
    {
        toehold = event->pos();
        resetting();
    }

    event->accept();
}

void MapInterface::mouseReleaseEvent(QMouseEvent* const event) //ok
{
    if (cursor() == Qt::PointingHandCursor)
    {
        for (auto object: _objects)
            object->release(&orentation_, event->pos());

        update();
        unsetCursor();
    }

    if (cursor() == Qt::OpenHandCursor)
    {
        toehold = event->pos();
        resetting();
        unsetCursor();
    }

    event->accept();
}

void MapInterface::mousePressEvent(QMouseEvent* const event) //ok
{
    switch (event->button())
    {
    case Qt::LeftButton:
        toehold = event->pos();
        start_p = orentation_.toLocal(toehold);

        setCursor(Qt::OpenHandCursor);
        for (auto object: _objects)
        {
            if (object->press(&orentation_, toehold))
                setCursor(Qt::PointingHandCursor);
        }

        break;

    case Qt::MiddleButton:
        toehold = rect().center();
        start_p = Local2d();
        rotation_ = 0;
        zoom_ = 0;
        resetting();
        break;

    default:
        break;
    }

    event->accept();
}

void MapInterface::wheelEvent(QWheelEvent* const event)
{
    toehold = event->position();
    start_p = orentation_.toLocal(toehold);

    const auto wheel = event->angleDelta().y();
    if (event->modifiers().testFlag(Qt::ControlModifier))
        rotation_ += wheel;
    else
        zoom_ += wheel;

    resetting();
    event->accept();
}


void MapInterface::resetting(){
    orentation_ = Orentation(start_p, toehold, rotation_, zoom_);
    update();
}

