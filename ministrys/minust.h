#ifndef MINUST_H
#define MINUST_H

#include <QDialog>

namespace Ui {
class MINUST;
}

class MINUST : public QDialog
{
    Q_OBJECT

public:
    explicit MINUST(bool isBlocked, QWidget *parent = 0);
    ~MINUST();

signals:
    void sendDataToMainForm(int, int, int, int, int);

private slots:
    void on_approveButton_clicked();

    void on_goToCourtButton_clicked();

private:
    Ui::MINUST *ui;
    int command;
    int arg1,arg2,arg3;
};

#endif // MINUST_H
