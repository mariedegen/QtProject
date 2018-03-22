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
     * @param i
     * @param r
     * @param pass
     * @param log
     */
    Compte(int i, Ressource r, QString pass, QString log);

    /**
     * @brief Compte Destructor
     */
    ~Compte();

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
     * @brief getRessource
     * @return
     */
    Ressource getRessource() const;

    /**
     * @brief setRessource
     * @param value
     */
    void setRessource(const Ressource &value);

    /**
     * @brief getLogin
     * @return
     */
    QString getLogin() const;

    /**
     * @brief setLogin
     * @param value
     */
    void setLogin(const QString &value);

    /**
     * @brief getPassword
     * @return
     */
    QString getPassword() const;

    /**
     * @brief setPassword
     * @param value
     */
    void setPassword(const QString &value);

    /**
     * @brief checkAccount
     * @param login
     * @param password
     * @return
     */
    static bool checkAccount(QString login, QString password);

    /**
     * @brief getCompteByIdRessource
     * @param id
     * @return
     */
    static Compte getCompteByIdRessource(int id);

};

#endif // COMPTE_H
