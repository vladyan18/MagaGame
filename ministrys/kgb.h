#ifndef KGB_H
#define KGB_H

#include <QDialog>
#include <Command.h>
#include <mainwindow.h>
#include <ministrys/iminister.h>

namespace Ui {
class KGB;
}

class KGB : public IMinister
{
    Q_OBJECT

public:
    explicit KGB(MainWindow *its, int power,bool isBlocked, QWidget *parent = 0);
    ~KGB();
signals:
    void sendDataToMainForm(Command);

private slots:
    void on_approveButton_clicked();

    void on_findMinButton_clicked();

    void on_defRolesButton_clicked();

    void receiveDataFromDial(int,int);
private:
    Ui::KGB *ui;
    int kgbPower;
};

#endif // KGB_H
