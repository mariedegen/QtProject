#ifndef COMPTE_H
#define COMPTE_H

#include <QString>
#include "ressource.h"

class Compte
{
    /*
        id : primary key, integer
        ressource : foreign key
        login : login, QString
        password : password, string
    */

private :
    int id;
    Ressource ressource;
    QString login;
    QString password;

public:
    /* Constructor */
    Compte();
    /* Destructor */
    ~Compte();

    /* Methods */
    int getId() const;
    void setId(int value);

    Ressource getRessource() const;
    void setRessource(const Ressource &value);

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

};

#endif // COMPTE_H
