#ifndef KGB_H
#define KGB_H

#include <QDialog>
#include <Command.h>

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
    void sendDataToMainForm(Command);

private slots:
    void on_approveButton_clicked();

    void on_findMinButton_clicked();

    void on_defRolesButton_clicked();

    void on_powerSpinBox_editingFinished();

    void receiveDataFromDial(int,int);
private:
    Ui::KGB *ui;
    Command c;
};

#endif // KGB_H
