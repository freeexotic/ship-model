#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName(QApplication::tr("Auto-Control-ship"));
    // setApplicationName Задает имя приложению, tr - используется для переведенного текста в классах
    app.setOrganizationName(QApplication::tr("Sirius"));
    // Имя организации часто используется в сочетании с именем приложения для определения местоположения, где будут сохраняться настройки и предпочтения пользователя
    app.setApplicationVersion(QApplication::tr("0.0.0"));
    // Задаёт версию приложения

    MainWindow window;
    window.show();

    return app.exec();
}
