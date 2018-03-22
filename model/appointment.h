#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "client.h"
#include "ressource.h"

class Appointment
{
private :
    int id;
    Client client;
    Ressource ressource;

public:
    /* Constructor & Destructor -----------------------------------*/
    /**
     * @brief Appointment constructor
     */
    Appointment();

    /**
     * @brief Appointment destructor
     */
    ~Appointment();

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
     * @brief getClient
     * @return
     */
    Client getClient() const;

    /**
     * @brief setClient
     * @param value
     */
    void setClient(const Client &value);

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
};

#endif // RDV_H
