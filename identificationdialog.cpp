#include "identificationdialog.h"
#include "ui_identificationdialog.h"

IdentificationDialog::IdentificationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdentificationDialog)
{
    ui->setupUi(this);
}

IdentificationDialog::~IdentificationDialog()
{
    delete ui;
}
