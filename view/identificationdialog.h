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

public:
    explicit IdentificationDialog(QWidget *parent = 0);
    ~IdentificationDialog();

private:
    Ui::IdentificationDialog *ui;

private slots :
    void check_authentification();
    void on_cancel_btn_clicked();
};

#endif // IDENTIFICATIONDIALOG_H
