#include "compte.h"

Compte::Compte()
{
    login = QString().isNull();
    password = QString().isNull();
}

Compte::~Compte()
{
    delete ressource;
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
