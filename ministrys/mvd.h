#ifndef MVD_H
#define MVD_H

#include <QDialog>

namespace Ui {
class MVD;
}

class MVD : public QDialog
{
    Q_OBJECT

public:
    explicit MVD(bool isBlocked, QWidget *parent = 0);
    ~MVD();
signals:
    void sendDataToMainForm(int, int, int, int, int);

public slots:
    void receiveDataFromDial(int,int);

private slots:
    void on_approveButton_clicked();

    void on_suppressRiotButton_clicked();

    void on_checkMinButton_clicked();

    void on_arestMin_clicked();

private:
    Ui::MVD *ui;
    int command;
    int arg1,arg2,arg3;
};

#endif // MVD_H
