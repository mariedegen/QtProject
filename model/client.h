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
    /* Constructor & Destructor -----------------------------------*/

    /**
     * @brief Client constructor
     */
    Client();

    /**
     * @brief Client constructor
     * @param lastName
     * @param firstName
     */
    Client(QString lastName, QString firstName);

    /**
     * @brief Client constructor
     * @param i The client's ID
     * @param lName The client's lastname
     * @param fName The client's firstname
     * @param a The client's address
     * @param c The client's town
     * @param zip The client's zip code
     * @param desc The client's description
     * @param phone The client's phone
     * @param date The appointment date
     * @param duration The duration of the appointemant
     * @param pri The priority
     */
    Client(int i, QString lName, QString fName, QString a, QString c, int zip, QString desc, int phone, QDate date, int duration, int pri);

    /**
     * @brief Client destructor
     */
    ~Client();

    /* Methods ----------------------------------------------------*/
    /**
     * @brief getId
     * @return The client's ID
     */
    int getId() const;

    /**
     * @brief getName
     * @return The client's name
     */
    QString getName() const;

    /**
     * @brief setName
     * @param value The client's name to set
     */
    void setName(const QString &value);

    /**
     * @brief getFirstName
     * @return The client's fisrtname
     */
    QString getFirstName() const;

    /**
     * @brief setFirstName
     * @param value The client's fisrtname to set
     */
    void setFirstName(const QString &value);

    /**
     * @brief getAdress
     * @return The client's address
     */
    QString getAdress() const;

    /**
     * @brief setAdress
     * @param value The client's address to set
     */
    void setAdress(const QString &value);

    /**
     * @brief getTown
     * @return The client's town
     */
    QString getTown() const;

    /**
     * @brief setTown
     * @param value The client's town to set
     */
    void setTown(const QString &value);

    /**
     * @brief getZipCode
     * @return The client's zip code
     */
    int getZipCode() const;

    /**
     * @brief setZipCode
     * @param value The client's zip code to set
     */
    void setZipCode(int value);

    /**
     * @brief getDescription
     * @return The client's description
     */
    QString getDescription() const;

    /**
     * @brief setDescription
     * @param value The client's description to set
     */
    void setDescription(const QString &value);

    /**
     * @brief getPhoneNumber
     * @return The client's phone number
     */
    int getPhoneNumber() const;

    /**
     * @brief setPhoneNumber
     * @param value The client's phone number to set
     */
    void setPhoneNumber(int value);

    /**
     * @brief getAppointmentDate
     * @return The appointment's date
     */
    QDate getAppointmentDate() const;

    /**
     * @brief setAppointmentDate
     * @param value The appointment's date to set
     */
    void setAppointmentDate(const QDate &value);

    /**
     * @brief getAppointmentDuration
     * @return The appointment's duration
     */
    int getAppointmentDuration() const;

    /**
     * @brief setAppointmentDuration
     * @param value The appointment's duration to set
     */
    void setAppointmentDuration(int value);

    /**
     * @brief getPriority
     * @return The appointment's priority
     */
    int getPriority() const;

    /**
     * @brief setPriority
     * @param value The appointment's priority to set
     */
    void setPriority(int value);

    /**
     * @brief getListClientByCriteria
     * @param id The Id of the client you are looking for
     * @param lastName The lastname of the client you are looking for
     * @param firstname The firstname of the client you are looking for
     * @return The result in a QSqlQueryModel object
     */
    static QSqlQueryModel* getListClientByCriteria(int id, QString lastName, QString firstname, QDate date1, QDate date2);

    /**
     * @brief addClientDB
     * @param lName The lastname of the client has registered in database
     * @param fName The lastname of the client has registered in database
     * @param a The address of the client has registered in database
     * @param c The town of the client has registered in database
     * @param desc The description of the client has registered in database
     * @param zip The zip code of the client has registered in database
     * @param phone The phone of the client has registered in database
     * @param date The date of the client has registered in database
     * @param duration The duration of the client has registered in database
     * @param pri The priority of the client has registered in database
     */
    static void addClientDB(QString lName, QString fName, QString a,  QString c, QString desc, QString zip, QString phone, QDate date, QString duration, QString pri, QModelIndexList list);

    /**
     * @brief deleteClient
     * @param ID The id of the client to delete
     */
    static void deleteClient(int ID);

    /**
     * @brief getClientByID
     * @param ID The client's id to recover
     * @return a Client objext
     */
    static Client getClientByID(int ID);

    /**
     * @brief modifyClientDB
     * @param lName The client's new lastname
     * @param fName The client's new firstname
     * @param a The client's new address
     * @param c The client's new town
     * @param desc The client's new description
     * @param zip The client's new zip code
     * @param phone The client's new phone
     * @param date The client's new date
     * @param duration The client's new duration
     * @param pri The client's new priority
     * @param ID Client ID to update
     */
    static void modifyClientDB(QString lName, QString fName, QString a,  QString c, QString desc, QString zip, QString phone, QDate date, QString duration, QString pri, int ID);

    /**
     * @brief modifyAppointmentClient
     * @param ID Client ID
     * @param list
     */
    static void modifyAppointmentClient(int ID, QModelIndexList list);

    /**
     * @brief getRessourceByClientID
     * @param id Client ID
     * @return a QSqlQueryModel object
     */
    static QSqlQueryModel * getRessourceByClientID(int id);
};

#endif // CLIENT_H
