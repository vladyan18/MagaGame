#ifndef MVD_H
#define MVD_H

#include <QDialog>
#include <Command.h>

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
    void sendDataToMainForm(Command);

public slots:
    void receiveDataFromDial(int,int);

private slots:
    void on_approveButton_clicked();

    void on_suppressRiotButton_clicked();

    void on_checkMinButton_clicked();

    void on_arestMin_clicked();

private:
    Ui::MVD *ui;
    Command c;
};

#endif // MVD_H
