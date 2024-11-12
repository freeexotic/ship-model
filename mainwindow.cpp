#include "mainwindow.h"
#include <QFontDatabase>
#include <QMenuBar>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    _mapinterface(std::make_shared<MapInterface>(nullptr)),
    _mapgrid(std::make_shared<MapGrid>(10, QColor(0, 0, 0), this))
{

    _mapinterface->AppendObject(_mapgrid);
    setCentralWidget(_mapinterface.get());
    QMenu* settingMenu = menuBar()->addMenu("File");
    settingMenu->addAction("Quit", this, &MainWindow::close, QKeySequence::Quit);


}
