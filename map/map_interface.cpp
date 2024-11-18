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
     // Включается режим сглаживания (Antialiasing), который улучшает качество отрисовки, делая линии и края объектов более плавными.
    painter.translate(0.5, 0.5);
    // Эта строка сдвигает систему координат на 0.5 пикселя по обеим осям (X и Y).
    // Этот сдвиг используется для улучшения точности отрисовки тонких линий и других объектов с четкими границами.
    // В некоторых случаях это помогает избежать проблем с "размыванием" линий из-за особенностей рендеринга пикселей.
    painter.setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
    // Устанавливается шрифт для текста, который будет использоваться при рисовании.
    // В данном случае используется системный шрифт с фиксированной шириной символов (FixedFont).
    // Это полезно для отображения моноширинного текста, например, в консольных приложениях или при отрисовке кода.


    for(const auto& obj : _objects){
        painter.save();
        obj->paint(&orentation_, &painter);
        painter.restore();
    }
    // paintEvent переопределяет метод в классе QWidget
    event->accept(); // сигнализирует фреймворку Qt, что событие было обработано текущим объектом и дальнейшее распространение события не требуется
}


void MapInterface::mouseMoveEvent(QMouseEvent* event)
{
    // if (cursor() == Qt::PointingHandCursor)
    // {
    //     for (auto object: _objects)
    //         object->move(&orentation_, event->pos());

    //     update();
    // }

    if (cursor() == Qt::OpenHandCursor)
    {
        toehold = event->pos();
        resetting();
    }

    event->accept();
}

void MapInterface::mouseReleaseEvent(QMouseEvent* const event)
{
    // if (cursor() == Qt::PointingHandCursor)
    // {
    //     for (auto object: _objects)
    //         object->release(&orentation_, event->pos());

    //     update();
    //     unsetCursor();
    // }

    if (cursor() == Qt::OpenHandCursor)
    {
        toehold = event->pos();
        resetting();
        unsetCursor();
    }

    event->accept();
}

void MapInterface::mousePressEvent(QMouseEvent* const event)
{
    switch (event->button())
    {
    case Qt::LeftButton:
        toehold = event->pos();
        start_p = orentation_.toLocal(toehold);
        //сохранение позиции курсора и перевод в локальную систему координат

        setCursor(Qt::OpenHandCursor);
        // for (auto object: _objects)
        // {
        //     if (object->press(&orentation_, toehold))
        //         setCursor(Qt::PointingHandCursor);
        // }
        // Выбор объекта
        break;

    case Qt::MiddleButton:
        toehold = rect().center();
        start_p = Local2d();
        rotation_ = 0;
        zoom_ = 0;
        resetting();
        break;

    // Сброс ориентации интерфейса
    default:
        break;
    }

    event->accept();
}

void MapInterface::wheelEvent(QWheelEvent* const event)
{
    toehold = event->position();
    start_p = orentation_.toLocal(toehold);
    //сохранение позиции курсора и перевод в локальную систему координат

    const auto wheel = event->angleDelta().y();
    if (event->modifiers().testFlag(Qt::ControlModifier))
        rotation_ += wheel;
    else
        zoom_ += wheel;
    //изменение угла вращения или приближения в зависимостри от нажатия Ctrl
    resetting();
    event->accept();
}

// Все методы с нажатием мышы это переопределение методов из класса QWidget


void MapInterface::resetting(){
    orentation_ = Orentation(start_p, toehold, rotation_, zoom_);
    // задание ориентации интерфейса
    update();
    // заново отрисовка объектов
}

