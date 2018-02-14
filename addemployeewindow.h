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

private:
    Ui::addEmployeeWindow *ui;
};

#endif // ADDEMPLOYEEWINDOW_H
