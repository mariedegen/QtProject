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

private:
    /* Attributes -------------------------------------------------*/
    Ui::SearchClient *ui;
    QString name;
    QString firstName;
    int id;
    QDate date1;
    QDate date2;

public:
    /* Constructor & Destructor -----------------------------------*/
    /**
     * @brief SearchClient Constructor
     * @param searchName
     * @param searchfName
     * @param id
     * @param parent
     */
    explicit SearchClient(QString searchName, QString searchfName, int id, QDate date1, QDate date2 ,QWidget *parent = 0);

    /**
     * @brief SearchClient Destructor
     */
    ~SearchClient();

private slots:
    /* Methods ----------------------------------------------------*/
    /**
     * @brief on_deleteclient_btn_clicked
     */
    void on_deleteclient_btn_clicked();

    /**
     * @brief on_editclient_btn_clicked
     */
    void on_editclient_btn_clicked();

    /**
     * @brief updateViewTable
     */
    void updateViewTable();
};

#endif // SEARCHCLIENT_H
