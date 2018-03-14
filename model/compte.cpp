#include "compte.h"

Compte::Compte()
{
    login = QString().isNull();
    password = QString().isNull();
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
