#include "mainwindow.h"
#include <QFontDatabase>
#include <QMenuBar>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    mapinterface_(std::make_shared<MapInterface>(nullptr)),
    mapgrid_(std::make_shared<MapGrid>(10, QColor(0, 0, 0), this)),
    pool_(std::make_shared<pool_object>(center, this)),
    boat_(std::make_shared<BoatModel>())
{

    mapinterface_->AppendObject(mapgrid_);
    mapinterface_->AppendObject(pool_);
    mapinterface_->AppendObject(boat_);

    setCentralWidget(mapinterface_.get());


    QMenu* settingMenu = menuBar()->addMenu("File");
    settingMenu->addAction("Quit", this, &MainWindow::close, QKeySequence::Quit);
}
