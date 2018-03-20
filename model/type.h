#ifndef TYPE_H
#define TYPE_H

#include <QString>
#include "db/initbdd.h"
#include <QtSql>

class Type
{
private:
    /*
     *   Id : primary key, integer
     *   Label : QString
     */

    int id;
    QString label;

public:
    /* Constructos & Destructor */
    Type();
    Type(const QString lbl);
    Type(int i, const QString lbl);
    ~Type();

    /* Methods */
    int getId() const;
    void setId(int value);

    QString getLabel() const;
    void setLabel(const QString &value);

    static QSqlQuery getListTypes();
    static int getIdTypeByName(QString nameType);
};

#endif // TYPE_H
