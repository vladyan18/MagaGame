#ifndef MINUST_H
#define MINUST_H

#include <QDialog>
#include <Command.h>
#include <mainwindow.h>
#include <ministrys/iminister.h>

namespace Ui {
class MINUST;
}

class MINUST : public IMinister
{
    Q_OBJECT

public:
    explicit MINUST(MainWindow *its, bool isBlocked, QWidget *parent = 0);
    ~MINUST();

signals:
    void sendDataToMainForm(Command);

private slots:
    void on_approveButton_clicked();

    void on_goToCourtButton_clicked();

private:
    Ui::MINUST *ui;
    Command c;
    int countOfTeams;
};

#endif // MINUST_H
