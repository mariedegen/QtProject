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

QStandardItemModel * Ressource::getRessources(){
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
            query.prepare("SELECT Nom, Prenom FROM TRessource WHERE IdType = ?");
            query.bindValue(0, model->record(i).value(0).toInt());
            query.exec();

            QSqlQueryModel *ressourcesModel = new QSqlQueryModel();
            ressourcesModel->setQuery(query);

            // Pour chaque ressource :
            for(int ressource(0) ; ressource < ressourcesModel->rowCount() ; ressource++) {
                // On créé un standard item pour la ressource (2)
                QStandardItem *ressourceItem = new QStandardItem(ressourcesModel->record(ressource).value(0).toString() + " " + ressourcesModel->record(ressource).value(1).toString());

                // On ajoute (2) en tant qu'enfant de (1)
                typeItem->appendRow(ressourceItem);
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
