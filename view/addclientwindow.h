#ifndef ADDCLIENTWINDOW_H
#define ADDCLIENTWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "ui_addclientwindow.h"
#include "db/initbdd.h"
#include "model/client.h"
#include <QStatusBar>

namespace Ui {
class addClientWindow;
}

class AddClientWindow : public QDialog
{
    Q_OBJECT
private:
    /* Attributes -------------------------------------------------*/
    Ui::addClientWindow *ui;
    int idClient;
    bool formIsCompleted();
    bool isNewClient;

public:
    /* Constructor & Destructor -----------------------------------*/
    /**
     * @brief AddClientWindow Constructor
     * @param parent
     * @param flag
     * @param idC
     */
    explicit AddClientWindow(QWidget *parent = 0, bool flag = true, int idC = 0);
    /**
     * @brief AddClientWindow Destructor
     */
    ~AddClientWindow();

private slots:
    /* Methods ----------------------------------------------------*/
    /**
     * @brief on_cancel_btn_clicked
     */
    void on_cancel_btn_clicked();

    /**
     * @brief on_ok_btn_clicked
     */
    void on_ok_btn_clicked();
    void on_modifyListRessource_clicked();
};

#endif // ADDCLIENTWINDOW_H
