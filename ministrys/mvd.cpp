#include "mvd.h"
#include "ui_mvd.h"
#include <dialogs/pickthemin.h>

#define NUMBER_OF_MINISTRY 7

MVD::MVD(bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MVD)
{
    ui->setupUi(this);
    command = -1;
    arg1 = -1;
    arg2 = -1;
    arg3 = -1;
    ui->label->setPixmap(QPixmap("mvd.png"));

    if (isBlocked)
    {
        ui->arestMin->setDisabled(true);
    }
}

MVD::~MVD()
{
    delete ui;
}

void MVD::on_suppressRiotButton_clicked()
{
    command = 1;

    ui->approveButton->setEnabled(true);
    ui->checkMinButton->setDisabled(true);
    ui->arestMin->setDisabled(true);
}

void MVD::on_checkMinButton_clicked()
{
    command = 2;

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
    command = com;
    arg1 = choice;
    ui->approveButton->setEnabled(true);
    ui->suppressRiotButton->setDisabled(true);
    ui->checkMinButton->setDisabled(true);
}

void MVD::on_approveButton_clicked()
{
    emit sendDataToMainForm(NUMBER_OF_MINISTRY, command, arg1, arg2, arg3);
    delete this;
}
