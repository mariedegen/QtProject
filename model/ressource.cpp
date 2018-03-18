#include "ressource.h"
#include "compte.h"
#include "db/initbdd.h"


Ressource::Ressource()
{
    lastname.isNull();
    firstname.isNull();
}

Ressource::Ressource(const QString ln, const QString fn)
{
    lastname = ln;
    firstname = fn;
}

Ressource::~Ressource()
{

}

int Ressource::getId() const
{
    return id;
}

QString Ressource::getLastname() const
{
    return lastname;
}

void Ressource::setLastname(const QString &value)
{
    lastname = value;
}

QString Ressource::getFirstname() const
{
    return firstname;
}

void Ressource::setFirstname(const QString &value)
{
    firstname = value;
}

Type Ressource::getType() const
{
    return type;
}

void Ressource::setType(const Type &value)
{
    type = value;
}

QSqlQueryModel * Ressource::getRessources(){
    QSqlDatabase db = InitBDD::getDatabaseInstance();

    if(db.isOpen()){
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM TRessource",db);
        InitBDD::Close_DB(db);
        return model;
    }else{
        qDebug() << "DataBase is closed.";
        return 0;
    }
}

void Ressource::addRessourceDB(QString name, QString fname, int idType){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);

    qDebug() << "before query";
    query.prepare("INSERT INTO TRessource (Nom, Prenom, IdType) VALUES (?,?,?)");
    query.bindValue(0, name);
    query.bindValue(1, fname);
    query.bindValue(2,idType);

    if(!query.exec())
        qDebug() << query.lastError().text();

    InitBDD::Close_DB(db);
}

void Ressource::addRessourceITDB(QString name, QString fname, int idType, QString login, QString mdp){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    query.prepare("INSERT INTO TRessource (Nom, Prenom, IdType) VALUES (?,?,?)");
    query.bindValue(0, name);
    query.bindValue(1, fname);
    query.bindValue(2,idType);
    query.exec();

    //add the ressource to TCompte
    int idressource = query.lastInsertId().toInt();
    query.prepare("INSERT INTO TCompte (IdRessource, Login, MdP) VALUES (?,?,?)");
    query.bindValue(0,idressource);
    query.bindValue(1, login);
    query.bindValue(2, mdp);
    query.exec();

    InitBDD::Close_DB(db);
}
