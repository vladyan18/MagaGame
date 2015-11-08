#ifndef MINDEF_H
#define MINDEF_H

#include <QDialog>
#include <Command.h>


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
    Command c;
};

#endif // MINDEF_H
