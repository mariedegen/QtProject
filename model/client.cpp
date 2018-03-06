#include "client.h"

Client::Client()
{
    lastName = QString().isNull();
    firstName = QString().isNull();
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

void Client::setId(int value)
{
    id = value;
}

QString Client::getName() const
{
    return lastName;
}

void Client::setName(const QString &value)
{
    lastName = value;
}

QString Client::getFirstName() const
{
    return firstName;
}

void Client::setFirstName(const QString &value)
{
    firstName = value;
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

std::list<Client> getListClient(QString name)
{

}
