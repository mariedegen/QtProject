#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>

namespace Ui {
class aboutWindow;
}

class AboutWindow : public QDialog
{
    Q_OBJECT
private:
    /* Attributes -------------------------------------------------*/
    Ui::aboutWindow *ui;

public:
    /* Constructor & Destructor -----------------------------------*/
    /**
     * @brief AboutWindow Constructor
     * @param parent
     */
    explicit AboutWindow(QWidget *parent = 0);

    /**
     * @brief AboutWindow Destructor
     */
    ~AboutWindow();


};

#endif // ABOUTWINDOW_H
