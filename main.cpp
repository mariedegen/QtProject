#include "mainwindow.h"
#include "view/identificationdialog.h"
#include "db/initbdd.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    IdentificationDialog i;

    if(i.exec()==QDialog::Accepted){
        InitBDD::Creation_BD();
        w.show();
        return a.exec();
    }
    return 0;
}
