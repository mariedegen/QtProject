#include "appointment.h"

Appointment::Appointment()
{

}

Appointment::~Appointment()
{

}

int Appointment::getId() const
{
    return id;
}

void Appointment::setId(int value)
{
    id = value;
}

Client Appointment::getClient() const
{
    return client;
}

void Appointment::setClient(const Client &value)
{
    client = value;
}

Ressource Appointment::getRessource() const
{
    return ressource;
}

void Appointment::setRessource(const Ressource &value)
{
    ressource = value;
}

QString Appointment::getPlanning(QDate date){
    QSqlDatabase db = InitBDD::getDatabaseInstance();

    if(db.isOpen()){
        QSqlQuery query(db);
        query.prepare("SELECT TClient.Nom, TClient.Prenom, TRessource.Nom, TRessource.Prenom, TClient.DureeRdv, TClient.Priorite FROM TRdv INNER JOIN TRessource ON TRessource.Id = TRdv.IdRessource INNER JOIN TClient ON TClient.Id = TRdv.IdClient WHERE TClient.DateRdv = ?");
        query.bindValue(0, date);
        query.exec();
        QString result;
        while(query.next()){
            result += "The Client " + query.value(0).toString() + " " + query.value(1).toString()
                    + " has an appointment with " + query.value(2).toString() + " " + query.value(3).toString() + " for a duration of "
                    + query.value(4).toString() + ". The client has a priority of " + query.value(5).toString() + ".\n";
        }
        return result;
        InitBDD::Close_DB(db);
    }else {
        qDebug() << "DataBase is closed.";
        return 0;
    }
}

