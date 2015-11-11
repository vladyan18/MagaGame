#ifndef MINFIN_H
#define MINFIN_H

#include <QDialog>
#include <QListWidgetItem>
#include <Command.h>
#include <mainwindow.h>
#include <getnumdialog.h>
#include <ministrys/iminister.h>


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
signals:
    void sendDataToMainForm(Command);

private slots:
    void on_listSpheres_itemDoubleClicked();

    void on_approveButton_clicked();
    void on_investmentButton_clicked();

    void on_playButton_clicked();

    void on_transButton_clicked();

private:
    Ui::MinFin *ui;
    void updateList();
    int cash;

    int list[3] = {1,1,1};
    int countOfTeams;
};

#endif // MINFIN_H
