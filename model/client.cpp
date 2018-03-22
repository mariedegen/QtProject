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

QSqlQueryModel* Client::getListClientByCriteria(int id, QString lastName, QString firstname, QDate date1, QDate date2){
     QSqlDatabase db = InitBDD::getDatabaseInstance();
     QSqlQuery query(db);
     QSqlQueryModel *model = new QSqlQueryModel();

     QDate date;
     date.setDate(2000, 1, 1);

     qDebug() << date.toString("yyyy-MM-dd");
     qDebug() << date1.toString("yyyy-MM-dd");
     qDebug() << date2.toString("yyyy-MM-dd");

     /**
      *  1 id + nom
      *  2 date + nom
      *  3 id + date + nom
      *  default nom
      */

     int numberQuery = 0; // nom

     //if(id != -1 /* et date */){ // id + date + noms
     //    numberQuery = 3;
     //} else if(){ // date + noms
     //    numberQuery = 2;
     //} else if(id != -1){ // id + noms
     //    numberQuery = 1;
     //}

     //TODO Remplacer par un switch (plus simple pour les dates)

     if(id != -1){
         query.prepare("SELECT id, nom, prenom, daterdv FROM TClient where id = ? AND daterdv BETWEEN ? AND ?");
         query.bindValue(0,id);
         query.bindValue(1,date1.toString("yyyy-MM-dd"));
         query.bindValue(2,date2.toString("yyyy-MM-dd"));
     } else if (id != -1 && (lastName.size() > 0 || firstname.size() > 0)) {
         query.prepare("SELECT id, nom, prenom, daterdv FROM TClient where where id = ? AND nom LIKE ? AND prenom LIKE ?");
         query.bindValue(0,id);
         query.bindValue(1,lastName + "%");
         query.bindValue(2,firstname+ "%");
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

void Client::addClientDB(QString lName, QString fName,QString a,  QString c, QString desc, QString zip, QString phone, QDate date, QString duration, QString pri, QModelIndexList list)
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

    //récupère l'id du client qui vient d'être ajouté
    int idC = query.lastInsertId().toInt();

    //Ajout des rdv
    foreach(const QModelIndex &index, list){
        query.prepare("SELECT Id FROM TRessource WHERE Nom = ?");
        query.bindValue(0,index.data(Qt::DisplayRole).toString());
        query.exec();
        query.next();
        //récupère l'id chaque ressource selectionnée
        int idR = query.value(0).toInt();

        //ajoute un rdv associé entre un client et une ressource, pour chaque ressource
        query.prepare("INSERT INTO TRdv (IdClient, IdRessource) VALUES (?,?)");
        query.bindValue(0,idC);
        query.bindValue(1,idR);
        query.exec();
    }
    InitBDD::Close_DB(db);
}

void Client::deleteClient(int ID){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    qDebug() << "britney bitch";
    //delete le client
    query.prepare("DELETE FROM TClient WHERE Id = ?");
    query.bindValue(0, ID);
    query.exec();
    //delete les rdv associés
    query.prepare("DELETE FROM TRdv WHERE IdClient in (SELECT IdClient FROM TRdv WHERE IDClient = ?)");
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
    //modifie le client
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

void Client::modifyAppointmentClient(int ID, QModelIndexList list){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    //modifie les rdv associés
    //On supprime tout les rdv associés au client
    //delete les rdv associés
    query.prepare("DELETE FROM TRdv WHERE IdClient in (SELECT IdClient FROM TRdv WHERE IDClient = ?)");
    query.bindValue(0, ID);
    query.exec();

    //On insère les nouveaux rdv
    foreach(const QModelIndex &index, list){
        query.prepare("SELECT Id FROM TRessource WHERE Nom = ?");
        query.bindValue(0,index.data(Qt::DisplayRole).toString());
        query.exec();
        query.next();
        //récupère l'id chaque ressource selectionnée
        int idR = query.value(0).toInt();

        //ajoute un rdv associé entre un client et une ressource, pour chaque ressource
        query.prepare("INSERT INTO TRdv (IdClient, IdRessource) VALUES (?,?)");
        query.bindValue(0,ID);
        query.bindValue(1,idR);
        query.exec();
    }
    InitBDD::Close_DB(db);
}

QSqlQueryModel * Client::getRessourceByClientID(int id){
    QSqlDatabase db = InitBDD::getDatabaseInstance();

    if(db.isOpen()){
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query(db);
        query.prepare("SELECT TRessource.Nom FROM TRdv INNER JOIN TRessource ON TRessource.Id = TRdv. IdRessource WHERE IdClient = ?");
        query.bindValue(0, id);
        query.exec();
        model->setQuery(query);
        InitBDD::Close_DB(db);
        return model;
    }else {
        qDebug() << "DataBase is closed.";
        return 0;
    }
}
