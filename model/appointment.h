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
     * @return The Appointment's ID
     */
    int getId() const;

    /**
     * @brief setId
     * @param value The id Value
     */
    void setId(int value);

    /**
     * @brief getClient
     * @return The the Appointment's client
     */
    Client getClient() const;

    /**
     * @brief setClient
     * @param value The Appointment's client
     */
    void setClient(const Client &value);

    /**
     * @brief getRessource
     * @return The Appointment's ressource
     */
    Ressource getRessource() const;

    /**
     * @brief setRessource
     * @param value The Appointment's value
     */
    void setRessource(const Ressource &value);
};

#endif // RDV_H
