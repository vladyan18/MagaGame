#ifndef MINFIN_H
#define MINFIN_H

#include <QDialog>
#include <QListWidgetItem>
#include <Command.h>
#include <mainwindow.h>
#include <getnumdialog.h>
#include <ministrys/iminister.h>
#include <dialogs/pickthemin.h>


class GetNumDialog;



namespace Ui {
class MinFin;
}


class MinFin : public IMinister
{
    Q_OBJECT

public:
    explicit MinFin(MainWindow *its, bool isBlocked, QWidget *parent = 0);
    ~MinFin();
    int cash;
signals:
    void sendDataToMainForm(Command);

private slots:
    void on_listSpheres_itemDoubleClicked();

    void on_approveButton_clicked();
    void on_investmentButton_clicked();

    void on_playButton_clicked();

    void receiveDataFromDial(int, int, int choice2);

private:
    Ui::MinFin *ui;
    void updateList();
    int list[3];

};

#endif // MINFIN_H
