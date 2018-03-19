#include "type.h"

Type::Type()
{
    label.isNull();
}

Type::Type(int i, const QString lbl)
{
    id = i;
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
    //TODO try to return a QStringList
    //InitBDD::Close_DB(db);
    return query;
}

int Type::getIdTypeByName(QString nameType){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    query.prepare("SELECT id FROM TType WHERE Label = ?");
    query.bindValue(0, nameType);
    query.exec();
    query.next();
    InitBDD::Close_DB(db);
    return query.value(0).toInt();
}
