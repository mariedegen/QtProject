#ifndef ADDCLIENTWINDOW_H
#define ADDCLIENTWINDOW_H

#include <QDialog>

namespace Ui {
class addClientWindow;
}

class addClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addClientWindow(QWidget *parent = 0);
    ~addClientWindow();

private:
    Ui::addClientWindow *ui;
};

#endif // ADDCLIENTWINDOW_H
