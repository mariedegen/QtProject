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
     * @param lbl
     */
    Type(const QString lbl);
    /**
     * @brief Type Constructor
     * @param i
     * @param lbl
     */
    Type(int i, const QString lbl);

    /**
     * @brief Type Destructor
     */
    ~Type();

    /* Methods ----------------------------------------------------*/
    /**
     * @brief getId
     * @return
     */
    int getId() const;

    /**
     * @brief setId
     * @param value
     */
    void setId(int value);

    /**
     * @brief getLabel
     * @return
     */
    QString getLabel() const;

    /**
     * @brief setLabel
     * @param value
     */
    void setLabel(const QString &value);

    /**
     * @brief getListTypes
     * @return
     */
    static QSqlQuery getListTypes();
    static int getIdTypeByName(QString nameType);
};

#endif // TYPE_H
