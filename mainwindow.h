#pragma once

#include <QMainWindow>
#include "map_grid.h"
#include "map_interface.h"
#include "pool_object.h"
#include "boat_model.h"
#include "controller_boat.h"

#include "global_2d.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    const Global2d center{55.698173788444564,37.949716003946584};
    MainWindow(QWidget *parent = nullptr);
    std::shared_ptr<MapInterface> mapinterface_;
    std::shared_ptr<MapGrid> mapgrid_;
    std::shared_ptr<pool_object> pool_;
    std::shared_ptr<BoatModel> boat_;
    std::shared_ptr<BoatController> controller_;

};
