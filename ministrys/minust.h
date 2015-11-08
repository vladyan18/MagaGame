#ifndef MINUST_H
#define MINUST_H

#include <QDialog>
#include <Command.h>

namespace Ui {
class MINUST;
}

class MINUST : public QDialog
{
    Q_OBJECT

public:
    explicit MINUST(bool isBlocked, QWidget *parent = 0);
    ~MINUST();

signals:
    void sendDataToMainForm(Command);

private slots:
    void on_approveButton_clicked();

    void on_goToCourtButton_clicked();

private:
    Ui::MINUST *ui;
    Command c;
};

#endif // MINUST_H
