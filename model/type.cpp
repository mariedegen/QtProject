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
