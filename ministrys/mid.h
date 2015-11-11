#ifndef MID_H
#define MID_H
#include <Command.h>
#include <QDialog>
#include <mainwindow.h>
#include <ministrys/iminister.h>

using namespace std;

namespace Ui {
class MID;
}

class MID : public IMinister
{
    Q_OBJECT

public:
    explicit MID(bool isBlocked, QWidget *parent = 0);
    explicit MID(MainWindow *its, bool isBlocked, int countOfTeams, bool **verbMatrix, QWidget *parent = 0);
    ~MID();

signals:
    void sendDataToMainForm(Command);


private slots:
    void on_approveButton_clicked();

    void on_diversionButton_clicked();

    void on_hookButton_clicked();

    void on_freeButton_clicked();

    void on_orderButton_clicked();

    void on_killButton_clicked();

    void on_spyButton_clicked();
    void receiveDataFromDial(int,int);
    void receivedFromMinForm(Command);
    void on_numOfCountrySpinBox_editingFinished();

    void on_numOfCountrySpinBox_valueChanged(int arg1);

private:
    Ui::MID *ui;
    Command c;
    bool orderFlag = false;
    int countOfTeams;
    bool **verbMatrix;
    MainWindow *parentForm;
};

#endif // MID_H
