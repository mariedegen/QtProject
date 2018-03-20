#include "client.h"

Client::Client()
{
    lastName = QString().isNull();
    firstName = QString().isNull();
    town = QString().isNull();
    description = QString().isNull();
    appointmentDate = QDate();
}

Client::Client(QString lName, QString fName)
{
    lastName = lName;
    firstName = fName;
    town = QString().isNull();
    description = QString().isNull();
    appointmentDate = QDate();
}

Client::Client(int i, QString lName, QString fName, QString c, QString desc, int zip, int phone, QDate date, int duration, int pri)
{
    id = i;
    lastName = lName;
    firstName = fName;
    town = c;
    description = desc;
    appointmentDate = date;
    zipCode = zip;
    phoneNumber = phone;
    appointmentDuration = duration;
    priority = pri;
}

Client::~Client()
{

}

int Client::getId() const
{
    return id;
}

QString Client::getName() const
{
    return lastName;
}

void Client::setName(const QString &value)
{
    lastName = toolbox::capitalize(value);
}

QString Client::getFirstName() const
{
    return firstName;
}

void Client::setFirstName(const QString &value)
{
    firstName = toolbox::capitalize(value);
}

QString Client::getAdress() const
{
    return adress;
}

void Client::setAdress(const QString &value)
{
    adress = value;
}

QString Client::getTown() const
{
    return town;
}

void Client::setTown(const QString &value)
{
    town = value;
}

int Client::getZipCode() const
{
    return zipCode;
}

void Client::setZipCode(int value)
{
    zipCode = value;
}

QString Client::getDescription() const
{
    return description;
}

void Client::setDescription(const QString &value)
{
    description = value;
}

int Client::getPhoneNumber() const
{
    return phoneNumber;
}

void Client::setPhoneNumber(int value)
{
    phoneNumber = value;
}

QDate Client::getAppointmentDate() const
{
    return appointmentDate;
}

void Client::setAppointmentDate(const QDate &value)
{
    appointmentDate = value;
}

int Client::getAppointmentDuration() const
{
    return appointmentDuration;
}

void Client::setAppointmentDuration(int value)
{
    appointmentDuration = value;
}

int Client::getPriority() const
{
    return priority;
}

void Client::setPriority(int value)
{
    priority = value;
}

QSqlQueryModel* Client::getListClientByCriteria(int id, QString lastName, QString firstname){
     QSqlDatabase db = InitBDD::getDatabaseInstance();
     QSqlQuery query(db);
     QSqlQueryModel *model = new QSqlQueryModel();

     if(id != -1){
         query.prepare("SELECT id, nom, prenom, daterdv FROM TClient where id = ?");
         query.bindValue(0,id);
     } else {
         query.prepare("SELECT id, nom, prenom, daterdv FROM TClient where nom LIKE ? AND prenom LIKE ?");
         query.bindValue(0,lastName + "%");
         query.bindValue(1,firstname+ "%");
     }
     query.exec();

     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, "ID");
     model->setHeaderData(1, Qt::Horizontal, "LastName");
     model->setHeaderData(2, Qt::Horizontal, "FirstName");
     model->setHeaderData(3, Qt::Horizontal, "Appointment Date");

     InitBDD::Close_DB(db);
     return model;
}

void Client::addClientDB(Client client)
{
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);

    query.prepare("INSERT INTO TClient (Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite ) VALUES (?,?,?,?,?,?,?,?,?,?,?)");
    query.bindValue(0,client.getName());
    query.bindValue(1,client.getFirstName());
    query.bindValue(2,client.getAdress());
    query.bindValue(3,client.getTown());
    query.bindValue(4,client.getZipCode());
    query.bindValue(5,client.getDescription());
    query.bindValue(6,client.getPhoneNumber());
    query.bindValue(7,client.getAppointmentDate());
    query.bindValue(8,client.getAppointmentDuration());
    query.bindValue(9,client.getPriority());
    query.exec();
    InitBDD::Close_DB(db);
}
