#ifndef ADDCLIENTWINDOW_H
#define ADDCLIENTWINDOW_H

#include <QDialog>

namespace Ui {
class addClientWindow;
}

class AddClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddClientWindow(QWidget *parent = 0);
    ~AddClientWindow();

private slots:
    void on_cancel_btn_clicked();

    void on_ok_btn_clicked();

private:
    Ui::addClientWindow *ui;
};

#endif // ADDCLIENTWINDOW_H