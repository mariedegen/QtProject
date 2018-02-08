#include "identificationdialog.h"
#include "ui_identificationdialog.h"

IdentificationDialog::IdentificationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdentificationDialog)
{
    ui->setupUi(this);
    //this->setWindowTitle("Identification");
    this->setWindowIcon(QIcon("icon/pig.png"));
    //this->setStyleSheet("background-color: white;");

    //Quit the window when the cancel_btn is clicked on
    connect(ui->cancel_btn,SIGNAL(clicked()),this, SLOT(close()));
}

IdentificationDialog::~IdentificationDialog()
{
    delete ui;
}


