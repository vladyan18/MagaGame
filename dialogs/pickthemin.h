#ifndef PICKTHEMIN_H
#define PICKTHEMIN_H

#include <QDialog>
#include <vector>
#include <ministrys/iminister.h>
using namespace std;

namespace Ui {
class PickTheMin;
}

class PickTheMin : public QDialog
{
    Q_OBJECT

public:
    explicit PickTheMin(IMinister *prnt,int com, int exc, QWidget *parent = 0);
        explicit PickTheMin(IMinister *prnt,int com, int exc, int mode, QWidget *parent = 0);
    explicit PickTheMin(IMinister *prnt, int com, int country,bool **verbMatrix, QWidget *parent = 0);
    ~PickTheMin();
signals:
    void sendDataToParent(int, int except = 0);
    void sendDataToParent(int, int, int);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_comboBox_activated(int index);

private:
    Ui::PickTheMin *ui;
    int withoutMin;
    int command;
    vector<int> ministers;
    int mode = 0;
    int choice;
    int choice2;
    int step = 1;
    IMinister *prnt;

};

#endif // PICKTHEMIN_H
