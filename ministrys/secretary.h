#ifndef SECRETARY_H
#define SECRETARY_H

#include <QDialog>

namespace Ui {
class Secretary;
}

class Secretary : public QDialog
{
    Q_OBJECT

public:
    explicit Secretary(QWidget *parent = 0);
    ~Secretary();

signals:
    void sendDataToMainForm(int, int, int, int, int);

private slots:
    void on_approveButton_clicked();

    void on_incLevelButton_clicked();
    void receiveDataFromDial(int,int);
    void receiveDataFromHelpDial(int,int);
    void on_helpButton_clicked();

private:
    Ui::Secretary *ui;
    int role;
    int command;
    int arg1;
    int arg2;
    int arg3;
};

#endif // SECRETARY_H
