#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addclientwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->centralWidget()->setStyleSheet("background-image: url(\":icon/nyan.gif\"); background-position: center;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClient_triggered()
{
    addClientWindow aCw;
    aCw.exec();

}
