#include "mid.h"
#include "ui_mid.h"
#include <QDebug>
#include <dialogs/pickthemin.h>

MID::MID(bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MID)
{


    command = -1;
    arg1 = -1;
    arg2 = -1;
    arg3 = -1;

    ui->setupUi(this);


    ui->gerb->setPixmap(QPixmap("gerb.png"));

    if (isBlocked)
    {
        ui->diversionButton->setDisabled(true);
        ui->hookButton->setDisabled(true);
        ui->killButton->setDisabled(true);
        ui->spyButton->setDisabled(true);
    }
}

MID::~MID()
{
    delete ui;
}

void MID::on_diversionButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(1,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    arg1 = ui->numOfCountrySpinBox->value();



    ui->hookButton->setDisabled(true);
    ui->freeButton->setDisabled(true);
    ui->orderButton->setDisabled(true);
    ui->killButton->setDisabled(true);
    ui->spyButton->setDisabled(true);
}

void MID::on_hookButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(2,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    arg1 = ui->numOfCountrySpinBox->value();




    ui->diversionButton->setDisabled(true);
    ui->freeButton->setDisabled(true);
    ui->orderButton->setDisabled(true);
    ui->killButton->setDisabled(true);
    ui->spyButton->setDisabled(true);
}

void MID::on_freeButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(3,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    arg1 = ui->numOfCountrySpinBox->value();



    ui->diversionButton->setDisabled(true);
    ui->hookButton->setDisabled(true);
    ui->orderButton->setDisabled(true);
    ui->killButton->setDisabled(true);
    ui->spyButton->setDisabled(true);
}

void MID::on_orderButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(4,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    arg1 = ui->numOfCountrySpinBox->value();



    ui->diversionButton->setDisabled(true);
    ui->freeButton->setDisabled(true);
    ui->hookButton->setDisabled(true);
    ui->killButton->setDisabled(true);
    ui->spyButton->setDisabled(true);
}

void MID::on_killButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(5,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    arg1 = ui->numOfCountrySpinBox->value();


    ui->diversionButton->setDisabled(true);
    ui->freeButton->setDisabled(true);
    ui->orderButton->setDisabled(true);
    ui->hookButton->setDisabled(true);
    ui->spyButton->setDisabled(true);
}

void MID::on_spyButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(6,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    arg1 = ui->numOfCountrySpinBox->value();


    ui->diversionButton->setDisabled(true);
    ui->freeButton->setDisabled(true);
    ui->orderButton->setDisabled(true);
    ui->killButton->setDisabled(true);
    ui->hookButton->setDisabled(true);
}

void MID::on_approveButton_clicked()
{

    emit sendDataToMainForm(5, command, arg1, arg2, arg3);
    delete this;
}
void MID::receiveDataFromDial(int com,int choice)
{
    command = com;
    arg2 = choice;
    ui->approveButton->setEnabled(true);
}


