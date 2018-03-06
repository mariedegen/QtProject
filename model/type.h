#ifndef TYPE_H
#define TYPE_H
#include <QString>

class Type
{
private:
    /*
     *   Id : primary key, integer
     *   Label : QString
     */

    int id;
    QString label;

public:
    /* Constructos & Destructor */
    Type();
    Type(const QString lbl);
    ~Type();

    /* Methods */
    int getId() const;
    void setId(int value);

    QString getLabel() const;
    void setLabel(const QString &value);
};

#endif // TYPE_H