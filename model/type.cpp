#include "type.h"

Type::Type()
{
    label.isNull();
}

Type::Type(const QString lbl)
{
    label = lbl;
}

Type::~Type()
{

}

int Type::getId() const
{
    return id;
}

void Type::setId(int value)
{
    id = value;
}

QString Type::getLabel() const
{
    return label;
}

void Type::setLabel(const QString &value)
{
    label = value;
}

QSqlQuery Type::getListTypes()
{
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TType");
    query.exec();
    //InitBDD::Close_DB(db);
    return query;
}
