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
    /*
     *   Id : primary key, integer
     *   Lastname : QString
     *   Firstname : QString
     *   IdType : foreign key, integer
     */

    int id;
    QString lastname;
    QString firstname;
    Type type;

public:
    /* Constructos & Destructor */
    Ressource();
    Ressource(QString lastname, QString firstname);
    Ressource(int i, const QString ln, const QString fn, Type type);
    Ressource(int i, const QString ln, const QString fn);
    ~Ressource();

    /* Methods */
    int getId() const;
    Type getBdListType() const;

    QString getLastname() const;
    void setLastname(const QString &value);

    QString getFirstname() const;
    void setFirstname(const QString &value);

    Type getType() const;
    void setType(const Type &value);

    QStandardItemModel *getRessources();

    int getMaxId();
    void addRessourceDB(QString name, QString fname, int idType);
    void addRessourceITDB(QString name, QString fname, int idType, QString login, QString mdp);
    static Ressource getRessourceById(int id);
    void modifyRessource(int ID, QString name, QString fname, int idType, QString login, QString mdp);
    static void deleteRessource(int ID);
};

#endif // RESSOURCE_H
