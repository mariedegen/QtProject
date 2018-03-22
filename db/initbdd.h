#ifndef INITBDD_H
#define INITBDD_H
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

class InitBDD
{
    private:
        /* Constructor & (Destructor) ---------------------------------*/
        /**
         * @brief InitBDD constructor
         */
        InitBDD();
    public:
        /* Methods ----------------------------------------------------*/
        /**
         * @brief Creation_BD
         * @return a boolean true if the BDD was created
         */
        static bool Creation_BD(void);

        /**
         * @brief Close_DB
         * @param db
         */
        static void Close_DB(QSqlDatabase db);

        /**
         * @brief getDatabaseInstance
         * @return the database's intance
         */
        static QSqlDatabase getDatabaseInstance();
};

#endif // INITBDD_H
