#ifndef MINHEL_H
#define MINHEL_H

#include <QDialog>
#include <Command.h>

namespace Ui {
class MinHel;
}

class MinHel : public QDialog
{
    Q_OBJECT

public:
    explicit MinHel(bool isBlocked, QWidget *parent = 0);
    ~MinHel();

signals:
    void sendDataToMainForm(Command);

private slots:
    void on_approveButton_clicked();

    void on_vaccineButton_clicked();

    void on_infectButton_clicked();

private:
    Ui::MinHel *ui;
    Command c;
};

#endif // MINHEL_H
