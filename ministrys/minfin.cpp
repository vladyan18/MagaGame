#include "minfin.h"
#include "ui_minfin.h"

int flag;

MinFin::MinFin(bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MinFin)
{
    command = -1;
    arg1 = -1;
    arg2 = -1;
    arg3 = -1;
    list[0] = 1;
    list[1] = 1;
    list[2] = 1;

    ui->setupUi(this);
    updateList();

    if (isBlocked)
    {
        ui->investmentButton->setDisabled(true);
    }
}

void MinFin::updateList() {
    flag = list[0] + list[1] + list[2];
    ui->listSpheres->clear();
    if (list[0]) {
    ui->listSpheres->addItem(QString("Сельское хозяйство"));
    }
    if (list[1])
    {
    ui->listSpheres->addItem(QString("Машиностроение"));
    }
    if (list[2])
    {
    ui->listSpheres->addItem(QString("Текстиль"));
    }
    if (flag < 3) {
        ui->investmentButton->setEnabled(1);
    }

}

MinFin::~MinFin()
{
    delete ui;
}

void MinFin::on_listSpheres_itemDoubleClicked()
{
    if (flag > 2) {
    list[ui->listSpheres->currentRow()] = 0;
    updateList();
    }
}

void MinFin::on_approveButton_clicked()
{
    sendDataToMainForm(2, command, arg1, arg2, arg3);
    delete this;
}

void MinFin::on_investmentButton_clicked()
{
    command = 1;
   if (list[0]) {
       arg1 = 1;
        if (list[1]) {
            arg2 = 2;
        } else {
            arg2 = 3;
        }
   } else {
       arg1 = 2;
       arg2 = 3;
   }

   ui->playButton->setDisabled(1);
   ui->approveButton->setEnabled(true);
}
