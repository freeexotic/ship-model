#pragma once

#include <QMainWindow>
#include "map_grid.h"
#include "map_interface.h"
#include "pool_object.h"

#include "global_2d.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    const Global2d center{55.698173788444564,37.949716003946584};
    MainWindow(QWidget *parent = nullptr);
    std::shared_ptr<MapInterface> _mapinterface;
    std::shared_ptr<MapGrid> _mapgrid;
    std::shared_ptr<pool_object> _pool;

};
