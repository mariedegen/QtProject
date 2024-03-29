#ifndef ADDEMPLOYEEWINDOW_H
#define ADDEMPLOYEEWINDOW_H

#include <QDialog>
#include "ui_addemployeewindow.h"
#include <QDebug>
#include "model/type.h"
#include <QSqlQuery>

namespace Ui {
class addEmployeeWindow;
}

class AddEmployeeWindow : public QDialog
{
    Q_OBJECT
private:
    /* Attributes -------------------------------------------------*/
    Ui::addEmployeeWindow *ui;
    void setTypesComboBox();
    bool isNewRessource;
    int idRessource;

public:
    /**
     * @brief AddEmployeeWindow constructor
     * @param parent The Qwidget parent
     * @param flag A boolean
     * @param idR The id of the em ployee
     */
    explicit AddEmployeeWindow(QWidget *parent = 0,  bool flag = true, int idR = 0);

    /**
     * @brief AddEmployeeWindow destructor
     */
    ~AddEmployeeWindow();

private slots:
    /* Methods ----------------------------------------------------*/
    /**
     * @brief on_cancel_btn_clicked
     */
    void on_cancel_btn_clicked();

    /**
     * @brief on_ok_btn_clicked
     */
    void on_ok_btn_clicked();

    /**
     * @brief on_type_comboBox_currentIndexChanged
     */
    void on_type_comboBox_currentIndexChanged();
};

#endif // ADDEMPLOYEEWINDOW_H
