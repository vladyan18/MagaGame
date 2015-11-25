#include "minfin.h"
#include "ui_minfin.h"


MinFin::MinFin(MainWindow *its, bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::MinFin)
{

    c.args[0] = 2;
    this->cash = its->cash;

    ui->setupUi(this);


    if (isBlocked)
    {
        ui->investmentButton->setDisabled(true);
    }

    this->countOfTeams = its->countOfTeams;

}

void MinFin::updateList() {

}

MinFin::~MinFin()
{
    delete ui;
}

void MinFin::on_listSpheres_itemDoubleClicked()
{
}

void MinFin::on_approveButton_clicked()
{
    sendDataToMainForm(c);
    delete this;
}

void MinFin::on_investmentButton_clicked()
{
   PickTheMin *dial = new PickTheMin(this,1,0,1,0);
   ui->playButton->setDisabled(1);
   dial->exec();
}

void MinFin::on_playButton_clicked()
{
    c.args[1] = 2;

    GetNumDialog *dial = new GetNumDialog(this, 8,0,500000, cash);
    this->setDisabled(true);
    dial->exec();

    dial = new GetNumDialog(this, 5,0,-100, 100);
    this->setDisabled(true);
    dial->exec();
}



void MinFin::receiveDataFromDial(int com,int choice, int choice2)
{
    c.args[1] = com;
    c.args[2] = choice;
    c.args[3] = choice2;
}
