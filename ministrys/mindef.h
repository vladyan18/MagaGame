#ifndef MINDEF_H
#define MINDEF_H

#include <QDialog>
#include <Command.h>
#include <mainwindow.h>
#include <getnumdialog.h>
#include <ministrys/iminister.h>


class GetNumDialog;

namespace Ui {
class MinDef;
}

class MinDef : public IMinister
{
    Q_OBJECT

public:
    explicit MinDef(MainWindow *its, bool isBlocked, QWidget *parent = 0);
    ~MinDef();
signals:
    void sendDataToMainForm(Command);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();


private:
    Ui::MinDef *ui;
    int countOfPRO;
    int countOfNukes;
    GetNumDialog *dial;

    int countOfTeams;
};

#endif // MINDEF_H
