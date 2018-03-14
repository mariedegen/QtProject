#ifndef ADDEMPLOYEEWINDOW_H
#define ADDEMPLOYEEWINDOW_H

#include <QDialog>
#include "ui_addemployeewindow.h"
#include <QDebug>
#include "model/type.h"
#include <QSqlQuery>

namespace Ui {
class addEmployeeWindow;
}

class AddEmployeeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmployeeWindow(QWidget *parent = 0);
    ~AddEmployeeWindow();

private slots:
    void on_cancel_btn_clicked();

    void on_ok_btn_clicked();

    void on_type_comboBox_currentIndexChanged();

private:
    Ui::addEmployeeWindow *ui;
    void setTypesComboBox();
};

#endif // ADDEMPLOYEEWINDOW_H
