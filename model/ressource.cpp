#include "ressource.h"

Ressource::Ressource()
{
    lastname.isNull();
    firstname.isNull();
}

Ressource::Ressource(const QString ln, const QString fn)
{
    lastname = ln;
    firstname = fn;
}

Ressource::~Ressource()
{

}

int Ressource::getId() const
{
    return id;
}

void Ressource::setId(int value)
{
    id = value;
}

QString Ressource::getLastname() const
{
    return lastname;
}

void Ressource::setLastname(const QString &value)
{
    lastname = value;
}

QString Ressource::getFirstname() const
{
    return firstname;
}

void Ressource::setFirstname(const QString &value)
{
    firstname = value;
}

Type Ressource::getType() const
{
    return type;
}

void Ressource::setType(const Type &value)
{
    type = value;
}
