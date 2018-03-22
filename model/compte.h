#ifndef COMPTE_H
#define COMPTE_H

#include <QString>
#include "ressource.h"

class Compte
{
private :
    int id;
    Ressource ressource;
    QString login;
    QString password;

public:
    /* Constructor & Destructor -----------------------------------*/
    /**
     * @brief Compte Constructor
     */
    Compte();

    /**
     * @brief Compte Constructor
     * @param i Account Id
     * @param r Account ressource
     * @param pass Account password
     * @param log Account Login
     */
    Compte(int i, Ressource r, QString pass, QString log);

    /**
     * @brief Compte Destructor
     */
    ~Compte();

    /* Methods ----------------------------------------------------*/
    /**
     * @brief getId
     * @return the Account Id
     */
    int getId() const;

    /**
     * @brief setId
     * @param value od the Account Id
     */
    void setId(int value);

    /**
     * @brief getRessource
     * @return the Account Ressource
     */
    Ressource getRessource() const;

    /**
     * @brief setRessource
     * @param value the Account Ressource to set
     */
    void setRessource(const Ressource &value);

    /**
     * @brief getLogin
     * @return the Account login
     */
    QString getLogin() const;

    /**
     * @brief setLogin
     * @param value of the Account login to set
     */
    void setLogin(const QString &value);

    /**
     * @brief getPassword
     * @return
     */
    QString getPassword() const;

    /**
     * @brief setPassword
     * @param value the Account password to set
     */
    void setPassword(const QString &value);

    /**
     * @brief checkAccount
     * @param login the Account login
     * @param password the Account password
     * @return a boolean at true if the Account exist
     */
    static bool checkAccount(QString login, QString password);

    /**
     * @brief getCompteByIdRessource
     * @param id the Account Id
     * @return the Account with the input id
     */
    static Compte getCompteByIdRessource(int id);

};

#endif // COMPTE_H
