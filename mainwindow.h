#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "view/addclientwindow.h"
#include "view/addemployeewindow.h"
#include "view/aboutwindow.h"
#include "view/searchclient.h"
#include "db/initbdd.h"
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updateRessourceTree();
    QStatusBar * getStatusBar();

private slots:
    void on_actionClient_triggered();

    void on_actionEmployees_triggered();

    void on_aboutaction_triggered();

    void on_search_btn_clicked();

    void on_delete_ressource_clicked();

    void on_edit_ressource_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
