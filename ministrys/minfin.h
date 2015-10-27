#ifndef MINFIN_H
#define MINFIN_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class MinFin;
}


class MinFin : public QDialog
{
    Q_OBJECT

public:
    explicit MinFin(bool isBlocked, QWidget *parent = 0);
    ~MinFin();
signals:
    void sendDataToMainForm(int, int, int, int, int);

private slots:
    void on_listSpheres_itemDoubleClicked();

    void on_approveButton_clicked();
    void on_investmentButton_clicked();

private:
    Ui::MinFin *ui;
    void updateList();
    int command;
    int arg1;
    int arg2;
    int arg3;
    int list[3];
};

#endif // MINFIN_H
