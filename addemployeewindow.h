#ifndef ADDEMPLOYEEWINDOW_H
#define ADDEMPLOYEEWINDOW_H

#include <QDialog>

namespace Ui {
class addEmployeeWindow;
}

class addEmployeeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addEmployeeWindow(QWidget *parent = 0);
    ~addEmployeeWindow();

private slots:
    void on_pushButton_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::addEmployeeWindow *ui;
};

#endif // ADDEMPLOYEEWINDOW_H
