#ifndef MINHEL_H
#define MINHEL_H

#include <QDialog>

namespace Ui {
class MinHel;
}

class MinHel : public QDialog
{
    Q_OBJECT

public:
    explicit MinHel(bool isBlocked, QWidget *parent = 0);
    ~MinHel();

signals:
    void sendDataToMainForm(int, int, int, int, int);

private slots:
    void on_approveButton_clicked();

    void on_vaccineButton_clicked();

    void on_infectButton_clicked();

private:
    Ui::MinHel *ui;
    int command;
    int arg1,arg2,arg3;
};

#endif // MINHEL_H
