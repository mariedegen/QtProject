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

Client::Client(int i, QString lName, QString fName, QString a, QString c,int zip, QString desc, int phone, QDate date, int duration, int pri)
{
    id = i;
    lastName = lName;
    firstName = fName;
    adress = a;
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

void Client::addClientDB(QString lName, QString fName,QString a,  QString c, QString desc, QString zip, QString phone, QDate date, QString duration, QString pri)
{
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    query.prepare("INSERT INTO TClient (Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite ) VALUES (?,?,?,?,?,?,?,?,?,?)");
    query.bindValue(0,lName);
    query.bindValue(1,fName);
    query.bindValue(2,a);
    query.bindValue(3,c);
    query.bindValue(4,zip.toInt());
    query.bindValue(5,desc);
    query.bindValue(6,phone.toInt());
    query.bindValue(7,date);
    query.bindValue(8,duration.toInt());
    query.bindValue(9,pri.toInt());
    query.exec();
    InitBDD::Close_DB(db);
}

void Client::deleteClient(int ID){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    qDebug() << "britney bitch";
    query.prepare("DELETE FROM TClient WHERE Id = ?");
    query.bindValue(0, ID);
    query.exec();
    InitBDD::Close_DB(db);
}

Client Client::getClientByID(int ID){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    query.prepare("Select * from TClient WHERE Id = ?");
    query.bindValue(0, ID);
    query.exec();
    query.next();
    Client c(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toInt(), query.value(6).toString(), query.value(7).toInt(), query.value(8).toDate(), query.value(9).toInt(), query.value(10).toInt());
    InitBDD::Close_DB(db);

    return c;

}

void Client::modifyClientDB(QString lName, QString fName,QString a,  QString c, QString desc, QString zip, QString phone, QDate date, QString duration, QString pri, int ID)
{
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    query.prepare("UPDATE TClient SET Nom = ?, Prenom = ?, Adresse = ?, Ville = ?, CP = ?, Commentaire = ?, Tel = ?, DateRdv = ?, DureeRdv = ?, Priorite=? WHERE Id = ?");
    query.bindValue(0,lName);
    query.bindValue(1,fName);
    query.bindValue(2,a);
    query.bindValue(3,c);
    query.bindValue(4,zip.toInt());
    query.bindValue(5,desc);
    query.bindValue(6,phone.toInt());
    query.bindValue(7,date);
    query.bindValue(8,duration.toInt());
    query.bindValue(9,pri.toInt());
    query.bindValue(10, ID);
    query.exec();
    InitBDD::Close_DB(db);
}
