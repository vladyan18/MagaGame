#ifndef SECRETARY_H
#define SECRETARY_H

#include <QDialog>
#include <Command.h>
#include <mainwindow.h>
#include <ministrys/iminister.h>

namespace Ui {
class Secretary;
}

class Secretary : public IMinister
{
    Q_OBJECT

public:
    explicit Secretary(MainWindow *its, QWidget *parent = 0);
    ~Secretary();

signals:
    void sendDataToMainForm(Command);

private slots:
    void on_approveButton_clicked();

    void on_incLevelButton_clicked();
    void receiveDataFromDial(int,int);
    void receiveDataFromHelpDial(int,int);
    void on_helpButton_clicked();

private:
    Ui::Secretary *ui;
    Command c;
    int countOfTeams;
};

#endif // SECRETARY_H
