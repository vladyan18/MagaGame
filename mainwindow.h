#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QWidget>
#include <QTcpSocket>
#include <Command.h>
using namespace std;



class Report;
class NetTransmitter;

struct Minister
{
    int lvl = 1;
    bool isBlocked = false;
};

class List {
public:
    int role;
    QString text;
    int command;
    int arg[5];
    int cost;
    List() {
     role = -1;
     command = -1;
     arg[0] = -1;
     arg[1] = -1;
     arg[2] = -1;
     arg[3] = -1;
     arg[4] = -1;
     cost = 0;
    }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addToList(int row, List *lt);
    int numTeam;
    Minister mins[10];
    int happinesOfPopulation;
    int cash;
    int numNukes;
    int numPRO;
    int profitSH;
    int profitMS;
    int profitTS;
    int countOfTeams = 0;
    Report* repDial;
    QString nameOfThisTeam;
    QString beautifyNumber(int);
    void readData();
    void readVerbMatrix();
    int checkForAgents();
private slots:
    void loose();

    void receivedFromForm(Command);
    void on_listWidget_itemDoubleClicked();

    void toStartConnection(QString, int);
    void onSokConnected();
    void onSokDisconnected();
    void readFromServer(int code);

    void on_numOfTeamSpinBox_editingFinished();
    void on_nameEdit_editingFinished();

    void on_incListSizeButton_clicked();
    void on_decListSizeButton_clicked();
    void on_connectionStatusDisp_clicked();
    void on_statButton_clicked();

    void on_presidentButton_clicked();
    void on_minFinButton_clicked();
    void on_minDefButton_clicked();
    void on_mvdButton_clicked();

    void on_approvePlan_clicked();

    void on_kgbButton_clicked();

    void on_midButton_clicked();

    void on_minUstButton_clicked();

    void on_minComButton_clicked();

    void on_minHelButton_clicked();

    void on_secretaryButton_clicked();

    void on_reportButton_clicked();

private:
    Ui::MainWindow *ui;
    List *cmds;
    int listSize;
    bool **verbedMatrix;

    int kgbpower;
    QTcpSocket* _sok;

    QString *namesOfMins;
    NetTransmitter *transmitter;
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
    void updateList();
    void clearList();

    void checkBlocks();
    void makeBudget();
    void getNumOfTeams();
    void sendDataToServer();
};



#endif // MAINWINDOW_H
