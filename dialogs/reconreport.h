#ifndef RECONREPORT_H
#define RECONREPORT_H

#include <QDialog>
#include <Command.h>
#include <mainwindow.h>

class List;

namespace Ui {
class ReconReport;
}

class ReconReport : public QDialog
{
    Q_OBJECT

public:
    explicit ReconReport(QWidget *parent = 0);
    ~ReconReport();
    void addCommand(int mode, int country, Command com);

    void receivedCommand(Command);
    void presidentSaid(Command);
    void minFinSaid(Command);
    void minDefSaid(Command);
    void KGBSaid(Command);
    void midSaid(Command);
    void minUstSaid(Command);
    void MVDSaid(Command);
    void minComSaid(Command);
    void minHelSaid(Command);
    void zamSaid(Command);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ReconReport *ui;
    List cmds;
    QString *namesOfMins;
    int currentMode;
};

#endif // RECONREPORT_H
