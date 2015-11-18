#ifndef MINCOM_H
#define MINCOM_H

#include <QDialog>
#include <Command.h>
#include <mainwindow.h>
#include <ministrys/iminister.h>

namespace Ui {
class MinCom;
}

class MinCom : public IMinister
{
    Q_OBJECT

public:
    explicit MinCom(MainWindow *its,bool isBlocked, QWidget *parent = 0);
    ~MinCom();

signals:
    void sendDataToMainForm(Command);

private slots:
    void on_approveButton_clicked();

    void on_refLiesButton_clicked();

    void on_improveMoodButton_clicked();

    void on_sayToMediaButton_clicked();

    void on_makeRiotButton_clicked();

private:
    Ui::MinCom *ui;
};

#endif // MINCOM_H
