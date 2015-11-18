#ifndef IMINISTER_H
#define IMINISTER_H
#include <QDialog>
#include <Command.h>
#include <QWidget>
#include <mainwindow.h>


class IMinister : public QDialog
{
public:
    IMinister() : QDialog() {}
    IMinister(QWidget *parent = 0) : QDialog(parent)
    {
     for (int i = 0; i <7; i++)
     c.args[i] = -1;
    }
    Command c;
    bool windowBlocked = false;
    int countOfTeams;
    int countOfNukes;
    int countOfPRO;
    MainWindow *its;
};

#endif // IMINISTER_H
