#ifndef PRESIDENT_H
#define PRESIDENT_H

#include <QDialog>
#include <QObject>
#include <QListWidgetItem>
#include <QWidget>

namespace Ui {
class President;
}

class President : public QDialog
{
    Q_OBJECT

public:
    explicit President(bool isBlocked, QWidget *parent = 0);
    ~President();
signals:
    void sendDataToMainForm(int, int, int, int, int);

private slots:
    void on_approveButton_clicked();
    void on_fireMin_clicked();
    void receiveDataFromDial(int,int);

private:
    Ui::President *ui;
    int command;
    int arg1;
    int arg2;
    int arg3;
};

#endif // PRESIDENT_H
