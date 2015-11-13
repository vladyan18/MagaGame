#include "minfin.h"
#include "ui_minfin.h"

int flag;

MinFin::MinFin(MainWindow *its, bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::MinFin)
{
    list[0] = 1;
    list[1] = 1;
    list[2] = 1;
    c.args[0] = 2;
    this->cash = its->cash;

    ui->setupUi(this);
    updateList();

    if (isBlocked)
    {
        ui->investmentButton->setDisabled(true);
    }

    this->countOfTeams = its->countOfTeams;

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
   ui->transButton->setDisabled(true);
}

void MinFin::on_playButton_clicked()
{
    c.args[1] = 2;
    GetNumDialog *dial = new GetNumDialog(this, 4,1, cash);
    dial->show();
    this->setDisabled(true);

    GetNumDialog* dial1 = new GetNumDialog(this, 5,-100, 100);
    dial1->show();
    this->setDisabled(true);

}

void MinFin::on_transButton_clicked()
{
    c.args[1] = 3;
    GetNumDialog *dial = new GetNumDialog(this, 4,1, cash);
    dial->show();
    this->setDisabled(true);

    GetNumDialog* dial1 = new GetNumDialog(this, 1,1, countOfTeams);
    dial1->show();
    this->setDisabled(true);
}
