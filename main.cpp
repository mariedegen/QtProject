#include "mainwindow.h"
#include "view/identificationdialog.h"
#include "db/initbdd.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    IdentificationDialog i;

    if(i.exec()==QDialog::Accepted){
        InitBDD::Creation_BD();
        MainWindow w;
        w.updateRessourceTree();
        w.show();
        int result = a.exec();

        InitBDD::Close_DB();
        return result;
    }
    return 0;
}
