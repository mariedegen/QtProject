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
     * @param lastname
     * @param firstname
     */
    Ressource(QString lastname, QString firstname);

    /**
     * @brief Ressource constructor
     * @param i
     * @param ln
     * @param fn
     * @param type
     */
    Ressource(int i, const QString ln, const QString fn, Type type);

    /**
     * @brief Ressource constructor
     * @param i
     * @param ln
     * @param fn
     */
    Ressource(int i, const QString ln, const QString fn);

    /**
     * @brief Ressource Destructor
     */
    ~Ressource();

    /* Methods ----------------------------------------------------*/
    /**
     * @brief getId
     * @return
     */
    int getId() const;

    /**
     * @brief getBdListType
     * @return
     */
    Type getBdListType() const;

    /**
     * @brief getLastname
     * @return
     */
    QString getLastname() const;

    /**
     * @brief setLastname
     * @param value
     */
    void setLastname(const QString &value);

    /**
     * @brief getFirstname
     * @return
     */
    QString getFirstname() const;

    /**
     * @brief setFirstname
     * @param value
     */
    void setFirstname(const QString &value);

    /**
     * @brief getType
     * @return
     */
    Type getType() const;

    /**
     * @brief setType
     * @param value
     */
    void setType(const Type &value);

    /**
     * @brief getRessources
     * @return
     */
    QStandardItemModel *getRessources();

    /**
     * @brief addRessourceDB
     * @param name
     * @param fname
     * @param idType
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
     * @param id
     * @return
     */
    static Ressource getRessourceById(int id);

    /**
     * @brief modifyRessource
     * @param ID
     * @param name
     * @param fname
     * @param idType
     * @param login
     * @param mdp
     */
    static void modifyRessource(int ID, QString name, QString fname, int idType, QString login, QString mdp);

    /**
     * @brief deleteRessource
     * @param ID
     */
    static void deleteRessource(int ID);
};

#endif // RESSOURCE_H
