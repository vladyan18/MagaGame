#ifndef MID_H
#define MID_H
#include <Command.h>
#include <QDialog>
using namespace std;

namespace Ui {
class MID;
}

class MID : public QDialog
{
    Q_OBJECT

public:
    explicit MID(bool isBlocked, QWidget *parent = 0);
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
private:
    Ui::MID *ui;
    Command c;
};

#endif // MID_H
