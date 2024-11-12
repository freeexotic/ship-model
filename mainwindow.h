#pragma once

#include <QMainWindow>
#include "map_grid.h"
#include "map_interface.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    std::shared_ptr<MapInterface> _mapinterface;
    std::shared_ptr<MapGrid> _mapgrid;
private:

};
