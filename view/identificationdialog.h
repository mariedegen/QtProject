#ifndef IDENTIFICATIONDIALOG_H
#define IDENTIFICATIONDIALOG_H

#include <QDialog>
#include "ui_identificationdialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include "model/compte.h"

namespace Ui {
class IdentificationDialog;
}

class IdentificationDialog : public QDialog
{
    Q_OBJECT
private:
    /* Attributes -------------------------------------------------*/
    Ui::IdentificationDialog *ui;

public:
    /* Constructor & Destructor -----------------------------------*/
    /**
     * @brief IdentificationDialog Constructor
     * @param parent
     */
    explicit IdentificationDialog(QWidget *parent = 0);

    /**
     * @brief IdentificationDialog Destructor
     */
    ~IdentificationDialog();

private slots :
    /* Methods ----------------------------------------------------*/
    /**
     * @brief check_authentification
     */
    void check_authentification();

    /**
     * @brief on_cancel_btn_clicked
     */
    void on_cancel_btn_clicked();
};

#endif // IDENTIFICATIONDIALOG_H
