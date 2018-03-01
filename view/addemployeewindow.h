#ifndef ADDEMPLOYEEWINDOW_H
#define ADDEMPLOYEEWINDOW_H

#include <QDialog>

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

private:
    Ui::addEmployeeWindow *ui;
};

#endif // ADDEMPLOYEEWINDOW_H
