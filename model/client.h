#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDate>
#include <list>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "./controller/toolbox.h"
#include "db/initbdd.h"

class Client
{
    /*
        id : primary key, integer,
        lastName : QString,
        firstName : QString,
        adress : QString,
        town : QString,
        zipcode : integer,
        description : QString,
        phoneNumber : integer,
        appointmentDate : date,
        appointmentDuration : QString,
        priority : integer.
    */
private :
    int id;
    QString lastName;
    QString firstName;
    QString adress;
    QString town;
    int zipCode;
    QString description;
    int phoneNumber;
    QDate appointmentDate;
    int appointmentDuration;
    int priority;

public:
    /* Constructor */
    Client();
    Client(QString lastName, QString firstName);

    /* Destructor */
    ~Client();

    /* Methods */
    int getId() const;
    void setCurrentId();

    QString getName() const;
    void setName(const QString &value);

    QString getFirstName() const;
    void setFirstName(const QString &value);

    QString getAdress() const;
    void setAdress(const QString &value);

    QString getTown() const;
    void setTown(const QString &value);

    int getZipCode() const;
    void setZipCode(int value);

    QString getDescription() const;
    void setDescription(const QString &value);

    int getPhoneNumber() const;
    void setPhoneNumber(int value);

    QDate getAppointmentDate() const;
    void setAppointmentDate(const QDate &value);

    int getAppointmentDuration() const;
    void setAppointmentDuration(int value);

    int getPriority() const;
    void setPriority(int value);

    QSqlQuery getListClientByCriteria(int id, QString lastName, QString firstname);

    int getMaxId() const;
};

#endif // CLIENT_H
