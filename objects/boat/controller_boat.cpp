#include "controller_boat.h"

#include "boat_obj.h"
#include <QGridLayout>
#include <QSlider>
#include <QTimer>
#include <QLabel>
#include <QDebug>

BoatController::BoatController(std::shared_ptr<BoatModel> boat, QWidget* parent)
    : QWidget(parent)
    , boat_(boat)
    , engine1Slider_(new QSlider(Qt::Vertical, this))
    , engine2Slider_(new QSlider(Qt::Vertical, this))
    , rudder1Slider_(new QSlider(Qt::Horizontal, this))
    , rudder2Slider_(new QSlider(Qt::Horizontal, this))
    , statusLabel_(new QLabel(this))
    , step_(0.1)
    , rudder1_(0.0)
    , rudder2_(0.0)
    , engine1_(0.0)
    , engine2_(0.0)
{
    setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));

    const auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &BoatController::updateFerry);
    timer->start(1000.0 * step_);

    engine1Slider_->setRange(-100, 100);
    engine1Slider_->setTickInterval(25);
    engine1Slider_->setTickPosition(QSlider::TicksBothSides);
    connect(engine1Slider_, &QSlider::valueChanged, this, &BoatController::updateFerry);

    engine2Slider_->setRange(-100, 100);
    engine2Slider_->setTickInterval(25);
    engine2Slider_->setTickPosition(QSlider::TicksBothSides);
    connect(engine2Slider_, &QSlider::valueChanged, this, &BoatController::updateFerry);

    rudder1Slider_->setRange(-100, +100);
    rudder1Slider_->setTickInterval(20);
    rudder1Slider_->setTickPosition(QSlider::TicksBelow);
    connect(rudder1Slider_, &QSlider::valueChanged, this, &BoatController::updateFerry);

    rudder2Slider_->setRange(-100, +100);
    rudder2Slider_->setTickInterval(20);
    rudder2Slider_->setTickPosition(QSlider::TicksBelow);
    connect(rudder2Slider_, &QSlider::valueChanged, this, &BoatController::updateFerry);


    statusLabel_->setAlignment(Qt::AlignCenter);



    const auto layout = new QGridLayout(this);
    layout->addWidget(engine1Slider_, 1, 0, 1, 1, Qt::AlignHCenter);
    layout->addWidget(engine2Slider_, 1, 1, 1, 1, Qt::AlignHCenter);
    layout->addWidget(rudder1Slider_, 2, 0, 1, 1, Qt::AlignVCenter);
    layout->addWidget(rudder2Slider_, 2, 1, 1, 1, Qt::AlignVCenter);
    layout->addWidget(statusLabel_, 4, 0, 1, 2, Qt::AlignVCenter);

    updateFerry();
}



void BoatController::updateFerry()
{
    qDebug() << "controll update";
    boat_->set_engine1_trust(0.01 * engine1Slider_->value());
    boat_->set_engine2_trust(0.01 * engine2Slider_->value());
    boat_->set_rudder1_angle(0.01 * rudder1Slider_->value());
    boat_->set_rudder2_angle(0.01 * rudder2Slider_->value());
}
