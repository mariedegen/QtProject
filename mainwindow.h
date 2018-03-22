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
    /* Constructor & Destructor -----------------------------------*/
    /**
     * @brief MainWindow Constructor
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * @brief MainWindow Destructor
     */
    ~MainWindow();

    /* Methods ----------------------------------------------------*/
    /**
     * @brief updateRessourceTree
     */
    void updateRessourceTree();

    /**
     * @brief getStatusBar
     * @return
     */
    QStatusBar * getStatusBar();

private slots:
    /**
     * @brief on_actionClient_triggered
     */
    void on_actionClient_triggered();

    /**
     * @brief on_actionEmployees_triggered
     */
    void on_actionEmployees_triggered();

    /**
     * @brief on_aboutaction_triggered
     */
    void on_aboutaction_triggered();

    /**
     * @brief on_search_btn_clicked
     */
    void on_search_btn_clicked();

    /**
     * @brief on_delete_ressource_clicked
     */
    void on_delete_ressource_clicked();

    /**
     * @brief on_edit_ressource_clicked
     */
    void on_edit_ressource_clicked();

    /**
     * @brief on_actionExit_triggered
     */
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
