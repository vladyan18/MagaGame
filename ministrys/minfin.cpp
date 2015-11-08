#include "minfin.h"
#include "ui_minfin.h"

int flag;

MinFin::MinFin(bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MinFin)
{
    c.args[0] = 2;

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
    sendDataToMainForm(c);
    delete this;
}

void MinFin::on_investmentButton_clicked()
{
    c.args[1] = 1;
   if (list[0]) {
       c.args[2] = 1;
        if (list[1]) {
            c.args[3] = 2;
        } else {
            c.args[3] = 3;
        }
   } else {
       c.args[2] = 2;
       c.args[3] = 3;
   }

   ui->playButton->setDisabled(1);
   ui->approveButton->setEnabled(true);
}
