#include "mainwindow.h"
#include "identificationdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    IdentificationDialog i;

    if(i.exec()==QDialog::Accepted){
        w.show();
        return a.exec();
    }
    return 0;
}
