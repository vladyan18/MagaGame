#ifndef PICKTHEMIN_H
#define PICKTHEMIN_H

#include <QDialog>

namespace Ui {
class PickTheMin;
}

class PickTheMin : public QDialog
{
    Q_OBJECT

public:
    explicit PickTheMin(int, int, QWidget *parent = 0);
    ~PickTheMin();
signals:
    void sendDataToParent(int, int except = 0);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PickTheMin *ui;
    int withoutMin;
    int command;
};

#endif // PICKTHEMIN_H
