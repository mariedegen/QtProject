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

public:
    explicit AddClientWindow(QWidget *parent = 0, bool flag = true, int idC = 0);
    ~AddClientWindow();

private slots:
    void on_cancel_btn_clicked();

    void on_ok_btn_clicked();

private:
    Ui::addClientWindow *ui;
    bool formIsCompleted();
    bool isNewClient;
    int idClient;
};

#endif // ADDCLIENTWINDOW_H
