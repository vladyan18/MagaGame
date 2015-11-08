#ifndef PRESIDENT_H
#define PRESIDENT_H

#include <QDialog>
#include <QObject>
#include <QListWidgetItem>
#include <QWidget>
#include <Command.h>

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
    void sendDataToMainForm(Command);

private slots:
    void on_approveButton_clicked();
    void on_fireMin_clicked();
    void receiveDataFromDial(int,int);

private:
    Ui::President *ui;
    Command c;
};

#endif // PRESIDENT_H
