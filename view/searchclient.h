#ifndef SEARCHCLIENT_H
#define SEARCHCLIENT_H

#include <QDialog>

namespace Ui {
class SearchClient;
}

class SearchClient : public QDialog
{
    Q_OBJECT

public:
    explicit SearchClient(QWidget *parent = 0);
    ~SearchClient();

private slots:
    void on_deleteclient_btn_clicked();

    void on_editclient_btn_clicked();

private:
    Ui::SearchClient *ui;
};

#endif // SEARCHCLIENT_H