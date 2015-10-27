#ifndef CONNECTDIAL_H
#define CONNECTDIAL_H

#include <QDialog>

namespace Ui {
class ConnectDial;
}

class ConnectDial : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDial(QWidget *parent = 0);
    ~ConnectDial();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

signals:
    void sendDataToMainForm(QString, int);

private:
    Ui::ConnectDial *ui;
};

#endif // CONNECTDIAL_H
