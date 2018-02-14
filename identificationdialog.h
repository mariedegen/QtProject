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

private:
    Ui::IdentificationDialog *ui;

private slots :
    void check_authentification();
    void on_cancel_btn_clicked();
};

#endif // IDENTIFICATIONDIALOG_H
