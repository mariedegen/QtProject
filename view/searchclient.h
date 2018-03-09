#ifndef SEARCHCLIENT_H
#define SEARCHCLIENT_H

#include "./controller/toolbox.h"
#include <QDialog>
#include <QSqlQuery>
#include <QDate>

namespace Ui {
class SearchClient;
}

class SearchClient : public QDialog
{
    Q_OBJECT

public:
    explicit SearchClient(QString searchName, QString searchfName, int id, QWidget *parent = 0);
    ~SearchClient();

private slots:
    void on_deleteclient_btn_clicked();
    void on_editclient_btn_clicked();
    void updateViewTable();

private:
    Ui::SearchClient *ui;
    QString name;
    QString firstName;
    int id;
};

#endif // SEARCHCLIENT_H
