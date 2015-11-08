#ifndef MINCOM_H
#define MINCOM_H

#include <QDialog>
#include <Command.h>

namespace Ui {
class MinCom;
}

class MinCom : public QDialog
{
    Q_OBJECT

public:
    explicit MinCom(bool isBlocked, QWidget *parent = 0);
    ~MinCom();

signals:
    void sendDataToMainForm(Command);

private slots:
    void on_approveButton_clicked();

    void on_refLiesButton_clicked();

    void on_improveMoodButton_clicked();

    void on_sayToMediaButton_clicked();

    void on_makeRiotButton_clicked();

private:
    Ui::MinCom *ui;
    Command c;
};

#endif // MINCOM_H
