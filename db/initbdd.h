#ifndef INITBDD_H
#define INITBDD_H
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

class InitBDD
{
    private:

        InitBDD();
    public:
        static bool Creation_BD(void);
        static void Close_DB(QSqlDatabase db);

        static QSqlDatabase getDatabaseInstance();
};

#endif // INITBDD_H
