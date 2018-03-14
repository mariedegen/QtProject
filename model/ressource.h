#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>
#include "type.h"
#include <QtSql>

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
    ~Ressource();

    /* Methods */
    int getId() const;
    void setId(int value);

    QString getLastname() const;
    void setLastname(const QString &value);

    QString getFirstname() const;
    void setFirstname(const QString &value);

    Type getType() const;
    void setType(const Type &value);

    QSqlQueryModel * getRessources();
};

#endif // RESSOURCE_H
