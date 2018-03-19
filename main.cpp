#include "mainwindow.h"
#include "view/identificationdialog.h"
#include "db/initbdd.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InitBDD::Creation_BD();
    IdentificationDialog i;

    if(i.exec()==QDialog::Accepted){
        MainWindow w;
        w.show();
        int result = a.exec();
        return result;
    }
    return 0;
}
