#ifndef KGB_H
#define KGB_H

#include <QDialog>

namespace Ui {
class KGB;
}

class KGB : public QDialog
{
    Q_OBJECT

public:
    explicit KGB(int,bool isBlocked, QWidget *parent = 0);
    ~KGB();
signals:
    void sendDataToMainForm(int, int, int, int, int);

private slots:
    void on_approveButton_clicked();

    void on_findMinButton_clicked();

    void on_defRolesButton_clicked();

    void on_powerSpinBox_editingFinished();

    void receiveDataFromDial(int,int);
private:
    Ui::KGB *ui;
    int command;
    int arg1;
    int arg2;
    int arg3;
};

#endif // KGB_H
