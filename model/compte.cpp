#include "compte.h"

Compte::Compte()
{
    login = QString().isNull();
    password = QString().isNull();
}

Compte::Compte(int i, Ressource r, QString pass, QString log)
{
    id = i;
    ressource = r;
    login = log;
    password = pass;
}

Compte::~Compte()
{

}

int Compte::getId() const
{
    return id;
}

void Compte::setId(int value)
{
    id = value;
}

Ressource Compte::getRessource() const
{
    return ressource;
}

void Compte::setRessource(const Ressource &value)
{
    ressource = value;
}

QString Compte::getLogin() const
{
    return login;
}

void Compte::setLogin(const QString &value)
{
    login = value;
}

QString Compte::getPassword() const
{
    return password;
}

void Compte::setPassword(const QString &value)
{
    password = value;
}

bool Compte::checkAccount(QString login, QString password)
{
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    query.prepare("SELECT Login FROM TCompte WHERE Login = ? AND MdP = ?");
    query.bindValue(0, login);
    query.bindValue(1, password);
    query.exec();
    query.next();
    InitBDD::Close_DB(db);

    if( query.value(0).toString().size() > 0 ){
        return true;
    } else {
        return false;
    }
}

Compte Compte::getCompteByIdRessource(int id){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    query.prepare("SELECT * from TCompte INNER JOIN TRessource ON TCompte.IdRessource = TRessource.Id WHERE IdRessource = ?");
    query.bindValue(0, id);
    query.exec();
    query.next();
    Ressource r(query.value(5).toInt(), query.value(6).toString(), query.value(7).toString());
    Compte c(query.value(0).toInt(),r, query.value(3).toString(), query.value(2).toString());
    InitBDD::Close_DB(db);

    return c;
}
