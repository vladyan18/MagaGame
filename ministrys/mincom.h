#ifndef MINCOM_H
#define MINCOM_H

#include <QDialog>

namespace Ui {
class MinCom;
}

class MinCom : public QDialog
{
    Q_OBJECT

public:
    explicit MinCom(bool isBlocked, QWidget *parent = 0);
    ~MinCom();

signals:
    void sendDataToMainForm(int, int, int, int, int);

private slots:
    void on_approveButton_clicked();

    void on_refLiesButton_clicked();

    void on_improveMoodButton_clicked();

    void on_sayToMediaButton_clicked();

    void on_makeRiotButton_clicked();

private:
    Ui::MinCom *ui;
    int command;
    int arg1,arg2,arg3;
};

#endif // MINCOM_H
