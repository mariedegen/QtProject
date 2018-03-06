#include "appointment.h"

Appointement::Appointement()
{

}

Appointement::~Appointement()
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

