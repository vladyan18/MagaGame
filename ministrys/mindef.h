#ifndef MINDEF_H
#define MINDEF_H

#include <QDialog>


namespace Ui {
class MinDef;
}

class MinDef : public QDialog
{
    Q_OBJECT

public:
    explicit MinDef(bool isBlocked, QWidget *parent = 0);
    ~MinDef();
signals:
    void sendDataToMainForm(int, int, int, int, int);

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
    int command;
    int arg1,arg2,arg3;
};

#endif // MINDEF_H
