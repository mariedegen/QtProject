#ifndef IDENTIFICATIONDIALOG_H
#define IDENTIFICATIONDIALOG_H

#include <QDialog>

namespace Ui {
class IdentificationDialog;
}

class IdentificationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IdentificationDialog(QWidget *parent = 0);
    ~IdentificationDialog();
    void check_authentification();

private:
    Ui::IdentificationDialog *ui;

};

#endif // IDENTIFICATIONDIALOG_H
