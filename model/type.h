#ifndef TYPE_H
#define TYPE_H

#include <QString>
#include "db/initbdd.h"
#include <QtSql>

class Type
{
private:
    int id;
    QString label;

public:
    /* Constructor & Destructor -----------------------------------*/
    /**
     * @brief Type Constructor
     */
    Type();

    /**
     * @brief Type Constructor
     * @param lbl The type label
     */
    Type(const QString lbl);
    /**
     * @brief Type Constructor
     * @param i The type id
     * @param lbl The type label
     */
    Type(int i, const QString lbl);

    /**
     * @brief Type Destructor
     */
    ~Type();

    /* Methods ----------------------------------------------------*/
    /**
     * @brief getId
     * @return The type id
     */
    int getId() const;

    /**
     * @brief setId
     * @param value of the type id to set
     */
    void setId(int value);

    /**
     * @brief getLabel
     * @return The type label
     */
    QString getLabel() const;

    /**
     * @brief setLabel
     * @param value The type label to set
     */
    void setLabel(const QString &value);

    /**
     * @brief getListTypes
     * @return The list of all types in the database
     */
    static QSqlQuery getListTypes();

    /**
     * @brief getIdTypeByName
     * @param nameThe name of the Type to look for
     * @return The id of the type found
     */
    static int getIdTypeByName(QString nameType);
};

#endif // TYPE_H
