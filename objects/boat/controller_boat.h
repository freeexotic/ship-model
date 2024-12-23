#pragma once

#include <QWidget>
#include <QElapsedTimer>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include "boat_obj.h"
#include "boat_model.h"

class BoatController : public QWidget
{
    Q_OBJECT

public:
    explicit BoatController(std::shared_ptr<BoatModel> boat, QWidget* parent = nullptr);
    virtual ~BoatController() = default;

private slots:
    void updateFerry();

private:
    std::shared_ptr<BoatModel> boat_;
    QSlider* const engine1Slider_;
    QSlider* const engine2Slider_;
    QSlider* const rudder1Slider_;
    QSlider* const rudder2Slider_;
    QLabel* const statusLabel_;

    const double step_;

    double rudder1_;
    double rudder2_;
    double engine1_;
    double engine2_;
};
