#include "mainwindow.h"
#include <QFontDatabase>
#include <QDockWidget>
#include <QMenuBar>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    mapinterface_(std::make_shared<MapInterface>(nullptr)),
    mapgrid_(std::make_shared<MapGrid>(10, QColor(0, 0, 0), this)),
    pool_(std::make_shared<pool_object>(center, this)),
    boat_(std::make_shared<BoatModel>(this)),
    controller_(std::make_shared<BoatController>(boat_))
{

    mapinterface_->AppendObject(mapgrid_);
    mapinterface_->AppendObject(pool_);
    mapinterface_->AppendObject(boat_);

    setCentralWidget(mapinterface_.get());

    const auto dock = new QDockWidget(tr("Control"));
    dock->setObjectName("Boat Controller");
    dock->setWidget(controller_.get());
    addDockWidget(Qt::RightDockWidgetArea, dock);

    QMenu* settingMenu = menuBar()->addMenu("File");
    settingMenu->addAction("Quit", this, &MainWindow::close, QKeySequence::Quit);
}
