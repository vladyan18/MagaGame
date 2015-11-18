#ifndef PRESIDENT_H
#define PRESIDENT_H

#include <QDialog>
#include <QObject>
#include <QListWidgetItem>
#include <QWidget>
#include <Command.h>
#include <mainwindow.h>
#include <ministrys/iminister.h>

namespace Ui {
class President;
}

class President : public IMinister
{
    Q_OBJECT

public:
    explicit President(MainWindow *its, bool isBlocked, QWidget *parent = 0);
    ~President();
signals:
    void sendDataToMainForm(Command);

private slots:
    void on_approveButton_clicked();
    void on_fireMin_clicked();
    void receiveDataFromDial(int,int);

    void on_giveNukesButton_clicked();

    void on_givePROButton_clicked();

    void on_giveFacButton_clicked();

private:
    Ui::President *ui;
};

#endif // PRESIDENT_H
