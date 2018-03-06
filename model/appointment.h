#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "client.h"
#include "ressource.h"

class Appointment
{
    /*
        id : primary key, integer,
        Client : foreign key
        Ressource : foreign key
    */
private :
    int id;
    Client client;
    Ressource ressource;

public:
    /* Constructor */
    Appointment();
    /* Destructor */
    ~Appointment();

    /* Methods */
    int getId() const;
    void setId(int value);

    Client getClient() const;
    void setClient(const Client &value);

    Ressource getRessource() const;
    void setRessource(const Ressource &value);
};

#endif // RDV_H
