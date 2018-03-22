#include "view/identificationdialog.h"

using namespace std;

IdentificationDialog::IdentificationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdentificationDialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
    connect(ui->connection_btn,SIGNAL(clicked()),this, SLOT(check_authentification()));
}

IdentificationDialog::~IdentificationDialog()
{
    delete ui;
}


void IdentificationDialog::check_authentification()
{
    if(Compte::checkAccount(ui->login_input->text(), ui->password_input->text()) ){
        accept();
    } else {
        QMessageBox::warning(this, "Erreur", "The data entered are wrong.");
        ui->password_input->clear();
    }
}

void IdentificationDialog::on_cancel_btn_clicked()
{
    close();
}
