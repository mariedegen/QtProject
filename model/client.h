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
     * @param c The client's country
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
     * @return
     */
    int getId() const;

    /**
     * @brief getName
     * @return
     */
    QString getName() const;

    /**
     * @brief setName
     * @param value
     */
    void setName(const QString &value);

    /**
     * @brief getFirstName
     * @return
     */
    QString getFirstName() const;

    /**
     * @brief setFirstName
     * @param value
     */
    void setFirstName(const QString &value);

    /**
     * @brief getAdress
     * @return
     */
    QString getAdress() const;

    /**
     * @brief setAdress
     * @param value
     */
    void setAdress(const QString &value);

    /**
     * @brief getTown
     * @return
     */
    QString getTown() const;

    /**
     * @brief setTown
     * @param value
     */
    void setTown(const QString &value);

    /**
     * @brief getZipCode
     * @return
     */
    int getZipCode() const;

    /**
     * @brief setZipCode
     * @param value
     */
    void setZipCode(int value);

    /**
     * @brief getDescription
     * @return
     */
    QString getDescription() const;

    /**
     * @brief setDescription
     * @param value
     */
    void setDescription(const QString &value);

    /**
     * @brief getPhoneNumber
     * @return
     */
    int getPhoneNumber() const;

    /**
     * @brief setPhoneNumber
     * @param value
     */
    void setPhoneNumber(int value);

    /**
     * @brief getAppointmentDate
     * @return
     */
    QDate getAppointmentDate() const;

    /**
     * @brief setAppointmentDate
     * @param value
     */
    void setAppointmentDate(const QDate &value);

    /**
     * @brief getAppointmentDuration
     * @return
     */
    int getAppointmentDuration() const;

    /**
     * @brief setAppointmentDuration
     * @param value
     */
    void setAppointmentDuration(int value);

    /**
     * @brief getPriority
     * @return
     */
    int getPriority() const;

    /**
     * @brief setPriority
     * @param value
     */
    void setPriority(int value);

    /**
     * @brief getListClientByCriteria
     * @param id
     * @param lastName
     * @param firstname
     * @return
     */
    static QSqlQueryModel* getListClientByCriteria(int id, QString lastName, QString firstname, QDate date1, QDate date2);

    /**
     * @brief addClientDB
     * @param lName
     * @param fName
     * @param a
     * @param c
     * @param desc
     * @param zip
     * @param phone
     * @param date
     * @param duration
     * @param pri
     */
    static void addClientDB(QString lName, QString fName, QString a,  QString c, QString desc, QString zip, QString phone, QDate date, QString duration, QString pri, QModelIndexList list);

    /**
     * @brief deleteClient
     * @param ID
     */
    static void deleteClient(int ID);

    /**
     * @brief getClientByID
     * @param ID
     * @return
     */
    static Client getClientByID(int ID);

    /**
     * @brief modifyClientDB
     * @param lName
     * @param fName
     * @param a
     * @param c
     * @param desc
     * @param zip
     * @param phone
     * @param date
     * @param duration
     * @param pri
     * @param ID
     */
    static void modifyClientDB(QString lName, QString fName, QString a,  QString c, QString desc, QString zip, QString phone, QDate date, QString duration, QString pri, int ID);

    /**
     * @brief modifyAppointmentClient
     * @param ID
     * @param list
     */
    static void modifyAppointmentClient(int ID, QModelIndexList list);

    /**
     * @brief getRessourceByClientID
     * @param id
     * @return
     */
    static QSqlQueryModel * getRessourceByClientID(int id);
};

#endif // CLIENT_H
