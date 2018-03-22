#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>
#include "type.h"
#include <QtSql>
#include <QStandardItem>
#include <QStandardItemModel>

class Compte;

class Ressource
{
private:
    int id;
    QString lastname;
    QString firstname;
    Type type;

public:
    /* Constructor & Destructor -----------------------------------*/
    /**
     * @brief Ressource constructor
     */
    Ressource();

    /**
     * @brief Ressource constructor
     * @param lastname the last name of the resource
     * @param firstname the first name of the resource
     */
    Ressource(QString lastname, QString firstname);

    /**
     * @brief Ressource constructor
     * @param i the id of the resource
     * @param ln the last name of the resource
     * @param fn the first name of the resource
     * @param type the type of the resource
     */
    Ressource(int i, const QString ln, const QString fn, Type type);

    /**
     * @brief Ressource constructor
     * @param i the id of the resource
     * @param ln the last name of the resource
     * @param fn the first name of the resource
     */
    Ressource(int i, const QString ln, const QString fn);

    /**
     * @brief Ressource Destructor
     */
    ~Ressource();

    /* Methods ----------------------------------------------------*/
    /**
     * @brief getId
     * @return the id of the resource
     */
    int getId() const;

    /**
     * @brief getBdListType
     * @return the type of the resource
     */
    Type getBdListType() const;

    /**
     * @brief getLastname
     * @return the last name of the resource
     */
    QString getLastname() const;

    /**
     * @brief setLastname
     * @param value of the last name of the resource to set
     */
    void setLastname(const QString &value);

    /**
     * @brief getFirstname
     * @return the first name of the resource
     */
    QString getFirstname() const;

    /**
     * @brief setFirstname
     * @param value of the first name of the resource
     */
    void setFirstname(const QString &value);

    /**
     * @brief getType
     * @return the type of the resource
     */
    Type getType() const;

    /**
     * @brief setType
     * @param value of the type of the resource to set
     */
    void setType(const Type &value);

    /**
     * @brief getRessourcesAddClient
     * @return model of the Ressource of the resource
     */
    static QSqlQueryModel *getRessourcesAddClient();

    /**
     * @brief getRessources
     * @return a QStandardItemModel object
     */
    QStandardItemModel *getRessourcesListView();

    /**
     * @brief addRessourceDB
     * @param name name of the ressource to add
     * @param fname first name of the ressource to add
     * @param idType Type of the ressource to add
     */
    static void addRessourceDB(QString name, QString fname, int idType);

    /**
     * @brief addRessourceITDB
     * @param name
     * @param fname
     * @param idType
     * @param login
     * @param mdp
     */
    static void addRessourceITDB(QString name, QString fname, int idType, QString login, QString mdp);

    /**
     * @brief getRessourceById
     * @param id Id of the resource sought
     * @return a Ressource object
     */
    static Ressource getRessourceById(int id);

    /**
     * @brief modifyRessource
     * @param ID The id of the resource to modify
     * @param name The new value of the resource last name
     * @param fname The new value of the resource first name
     * @param idType The new value of the resource id Type
     * @param login The new value of the resource login
     * @param mdp The new value of the resource password
     */
    static void modifyRessource(int ID, QString name, QString fname, int idType, QString login, QString mdp);

    /**
     * @brief deleteRessource
     * @param ID The id of the resource to delete
     */
    static void deleteRessource(int ID);
};

#endif // RESSOURCE_H
