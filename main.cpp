#include "mainwindow.h"
#include "identificationdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    IdentificationDialog i;
    i.show();
    //w.show();

    return a.exec();
}
