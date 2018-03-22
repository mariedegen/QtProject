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

Ressource::Ressource(int i, const QString ln, const QString fn)
{
    id = i;
    lastname = ln;
    firstname = fn;
}

Ressource::Ressource(int i, const QString ln, const QString fn, Type t){
    id = i;
    lastname = ln;
    firstname = fn;
    type = t;
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

QSqlQueryModel * Ressource::getRessourcesAddClient(){
    QSqlDatabase db = InitBDD::getDatabaseInstance();

    if(db.isOpen()){
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query(db);
        query.prepare("SELECT Nom FROM TRessource");
        query.exec();
        model->setQuery(query);
        InitBDD::Close_DB(db);
        return model;
    }else {
        qDebug() << "DataBase is closed.";
        return 0;
    }
}



QStandardItemModel * Ressource::getRessourcesListView(){
    QSqlDatabase db = InitBDD::getDatabaseInstance();

    if(db.isOpen()){
        QStandardItemModel * standardModel = new QStandardItemModel() ;
        QStandardItem *rootNode = standardModel->invisibleRootItem();

        // On query tous les types de ressources
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT Id, Label FROM TType",db);

        // Pour chaque type de ressource :
        for(int i(0) ; i < model->rowCount() ; i++) {
            // On créé un standard item portant le nom du type de ressource (1)
            QStandardItem *typeItem = new QStandardItem(model->record(i).value(1).toString());

            // On ajoute (1) en tant qu'enfant de rootNode
            rootNode->appendRow(typeItem);

            // On query toutes les ressources du type actuel
            QSqlQuery query(db);
            query.prepare("SELECT Nom, Prenom, Id FROM TRessource WHERE IdType = ?");
            query.bindValue(0, model->record(i).value(0).toInt());
            query.exec();

            QSqlQueryModel *ressourcesModel = new QSqlQueryModel();
            ressourcesModel->setQuery(query);

            // Pour chaque ressource :
            for(int ressource(0) ; ressource < ressourcesModel->rowCount() ; ressource++) {
                // On créé un standard item pour la ressource (2)
                QStandardItem *ressourceItem = new QStandardItem(ressourcesModel->record(ressource).value(0).toString() + " " + ressourcesModel->record(ressource).value(1).toString());
                QStandardItem *idItem = new QStandardItem(ressourcesModel->record(ressource).value(2).toString());

                QList<QStandardItem*> row;
                row << ressourceItem << idItem;

                // On ajoute (2) en tant qu'enfant de (1)
                typeItem->appendRow(row);
            }
        }

        InitBDD::Close_DB(db);
        return standardModel;
    }else{
        qDebug() << "DataBase is closed.";
        return 0;
    }
}

void Ressource::addRessourceDB(QString name, QString fname, int idType){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    query.prepare("INSERT INTO TRessource (Nom, Prenom, IdType) VALUES (?,?,?)");
    query.bindValue(0, name);
    query.bindValue(1, fname);
    query.bindValue(2,idType);
    query.exec();

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

Ressource Ressource::getRessourceById(int id){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    query.prepare("Select TRessource.Id, TRessource.Nom, TRessource.Prenom, TRessource.IdType, TType.Id, TType.Label from TRessource INNER JOIN TType ON TRessource.IdType = TType.Id WHERE TRessource.Id = ?");
    query.bindValue(0, id);
    query.exec();
    query.next();
    Type type(query.value(4).toInt(), query.value(5).toString());
    Ressource ressource(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), type);
    InitBDD::Close_DB(db);

    return ressource;
}


void Ressource::modifyRessource(int ID, QString name, QString fname, int idType, QString login, QString mdp){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    if(idType != 7){ // IdType de l'informaticien = 7, donc si on est pas informaticien :
        query.prepare("UPDATE TRessource SET Nom = ?, Prenom = ?, IdType = ? WHERE Id = ?");
        query.bindValue(0, name);
        query.bindValue(1, fname);
        query.bindValue(2,idType);
        query.bindValue(3, ID);
        query.exec();

        //on verifie qu'il n'était pas informaticien avant, sinon on supprime le compte
        query.prepare("SELECT * from TCompte WHERE IdRessource = ?");
        query.bindValue(0, ID);
        query.exec();

        if(query.next()){
            //supprime le compte
            query.prepare("DELETE FROM TCompte WHERE IdRessource = ? ");
            query.bindValue(0, ID);
            query.exec();
        }
    }else{ //si est informaticien
        query.prepare("UPDATE TRessource SET Nom = ?, Prenom = ?, IdType = ? WHERE Id = ?");
        query.bindValue(0, name);
        query.bindValue(1, fname);
        query.bindValue(2,idType);
        query.bindValue(3, ID);
        query.exec();

        //s'il avait deja un compte on met à jour sinon on crée
        query.prepare("SELECT * from TCompte WHERE IdRessource = ?");
        query.bindValue(0, ID);
        query.exec();
        if(query.next()){
            //on update
            query.prepare("UPDATE TCompte SET Login = ? , MdP = ? WHERE IdRessource = ?");
            query.bindValue(0,login);
            query.bindValue(1, mdp);
            query.bindValue(2, ID);
            query.exec();
        }else {
            //on crée
            query.prepare("INSERT INTO TCompte (IdRessource, Login, MdP) VALUES (?,?,?)");
            query.bindValue(0,ID);
            query.bindValue(1, login);
            query.bindValue(2, mdp);
            query.exec();

        }
    }
    InitBDD::Close_DB(db);
}

void Ressource::deleteRessource(int ID){
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    //on verifie qu'il n'était pas informaticien avant, sinon on supprime le compte
    query.prepare("SELECT * from TCompte WHERE IdRessource = ?");
    query.bindValue(0, ID);
    query.exec();

    if(query.next()){
        //supprime le compte
        query.prepare("DELETE FROM TCompte WHERE IdRessource = ? ");
        query.bindValue(0, ID);
        query.exec();
    }

    //On supprime la ressource
    query.prepare("DELETE FROM TRessource WHERE Id = ? ");
    query.bindValue(0, ID);
    query.exec();

    InitBDD::Close_DB(db);
}
