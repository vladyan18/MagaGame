#include "mvd.h"
#include "ui_mvd.h"
#include <dialogs/pickthemin.h>

#define NUMBER_OF_MINISTRY 7

MVD::MVD(MainWindow *its, bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::MVD)
{
    ui->setupUi(this);
    c.args[0] = NUMBER_OF_MINISTRY;

    if (isBlocked)
    {
        ui->arestMin->setDisabled(true);
    }

    this->countOfTeams = its->countOfTeams;

}

MVD::~MVD()
{
    delete ui;
}

void MVD::on_suppressRiotButton_clicked()
{
    c.args[1] = 1;

    ui->approveButton->setEnabled(true);
    ui->checkMinButton->setDisabled(true);
    ui->arestMin->setDisabled(true);
}

void MVD::on_checkMinButton_clicked()
{
    c.args[1] = 2;

    ui->approveButton->setEnabled(true);
    ui->suppressRiotButton->setDisabled(true);
    ui->arestMin->setDisabled(true);
}

void MVD::on_arestMin_clicked()
{
    PickTheMin *pickDial = new PickTheMin(3,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
}

void MVD::receiveDataFromDial(int com,int choice)
{
    c.args[1] = com;
    c.args[2] = choice;
    ui->approveButton->setEnabled(true);
    ui->suppressRiotButton->setDisabled(true);
    ui->checkMinButton->setDisabled(true);
}

void MVD::on_approveButton_clicked()
{
    emit sendDataToMainForm(c);
    delete this;
}
