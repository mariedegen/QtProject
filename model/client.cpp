#include "client.h"

Client::Client()
{
    this->setCurrentId();
    lastName = QString().isNull();
    firstName = QString().isNull();
    town = QString().isNull();
    description = QString().isNull();
    appointmentDate = QDate();
}

Client::Client(QString lName, QString fName)
{
    this->setCurrentId();
    lastName = lName;
    firstName = fName;
    town = QString().isNull();
    description = QString().isNull();
    appointmentDate = QDate();
}

Client::~Client()
{

}

int Client::getId() const
{
    return id;
}

void Client::setCurrentId()
{
    id = this->getMaxId()+1;
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

int Client::getMaxId() const
{
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    query.prepare("SELECT max(id) FROM TClient");
    query.exec();
    query.next();
    InitBDD::Close_DB(db);
    return query.value(0).toInt();
}

QSqlQuery Client::getListClientByCriteria(int id, QString lastName, QString firstname){
     QSqlDatabase db = InitBDD::getDatabaseInstance();
     QSqlQuery query(db);
     if(id != -1){
         query.prepare("SELECT id, nom, prenom, daterdv FROM TClient where id = ?");
         query.bindValue(0,id);
     } else {
         query.prepare("SELECT id, nom, prenom, daterdv FROM TClient where nom LIKE ? AND prenom LIKE ?");
         query.bindValue(0,lastName + "%");
         query.bindValue(1,firstname+ "%");
     }
     query.exec();
     //InitBDD::Close_DB(db);
     return query;
}

// TODO add client to DB
