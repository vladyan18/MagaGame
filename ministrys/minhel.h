#ifndef MINHEL_H
#define MINHEL_H

#include <QDialog>
#include <Command.h>
#include <mainwindow.h>
#include <ministrys/iminister.h>

namespace Ui {
class MinHel;
}

class MinHel : public IMinister
{
    Q_OBJECT

public:
    explicit MinHel(MainWindow *its, bool isBlocked, QWidget *parent = 0);
    ~MinHel();

signals:
    void sendDataToMainForm(Command);

private slots:
    void on_approveButton_clicked();

    void on_vaccineButton_clicked();

    void on_infectButton_clicked();

private:
    Ui::MinHel *ui;
};

#endif // MINHEL_H
