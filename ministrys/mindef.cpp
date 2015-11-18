#include "mindef.h"
#include "ui_mindef.h"

MinDef::MinDef(MainWindow *its, bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::MinDef)
{
    ui->setupUi(this);
    c.args[0] = 3;

    if (isBlocked)
    {

    }

    this->countOfTeams = its->countOfTeams;
    this->countOfNukes = its->numNukes;
    this->countOfPRO = its->numPRO;

    if (countOfTeams < 1)
    {
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_6->setDisabled(true);
        ui->pushButton_7->setDisabled(true);
        ui->pushButton_8->setDisabled(true);
    }

}

MinDef::~MinDef()
{
    delete ui;
}

void MinDef::on_pushButton_clicked()
{
    // 3 - номер роли
    sendDataToMainForm(c);
    delete this;
}



void MinDef::on_pushButton_2_clicked()
{
    c.args[1] = 1;
    dial = new GetNumDialog(this,2,0,-countOfNukes,1000);
    this->setDisabled(true);
    dial->exec();


    ui->pushButton_3->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_7->setDisabled(1);
    ui->pushButton_8->setDisabled(1);


}

void MinDef::on_pushButton_3_clicked()
{
    c.args[1] = 2;
    dial = new GetNumDialog(this,2,0,-countOfPRO,1000);
    this->setDisabled(true);
    dial->exec();


    ui->pushButton_2->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_7->setDisabled(1);
    ui->pushButton_8->setDisabled(1);


}



void MinDef::on_pushButton_7_clicked()
{
    c.args[1] = 3;

    dial = new GetNumDialog(this,1,3,1,countOfTeams);
    this->setDisabled(true);
    dial->exec();


    ui->pushButton_2->setDisabled(1);
    ui->pushButton_3->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_8->setDisabled(1);



}

void MinDef::on_pushButton_4_clicked()
{
    c.args[1] = 4;
    dial = new GetNumDialog(this,2,0,1,countOfPRO);
    this->setDisabled(true);
    dial->exec();


    ui->pushButton_2->setDisabled(1);
    ui->pushButton_3->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_7->setDisabled(1);
    ui->pushButton_8->setDisabled(1);

}

void MinDef::on_pushButton_8_clicked()
{
    c.args[1] = 5;
    dial = new GetNumDialog(this,1,0,1,countOfTeams);
    this->setDisabled(true);
    dial->exec();



    ui->pushButton_2->setDisabled(1);
    ui->pushButton_3->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_7->setDisabled(1);


}

void MinDef::on_pushButton_6_clicked()
{
    c.args[1] = 6;
    dial = new GetNumDialog(this,1,0,1,countOfTeams);
    this->setDisabled(true);
    dial->exec();


    ui->pushButton_2->setDisabled(1);
    ui->pushButton_3->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_7->setDisabled(1);
    ui->pushButton_8->setDisabled(1);

}

void MinDef::on_pushButton_5_clicked()
{
    c.args[1] = 7;
    dial = new GetNumDialog(this,1,0,1,countOfTeams);
    this->setDisabled(true);
    dial->exec();


    ui->pushButton_2->setDisabled(1);
    ui->pushButton_3->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_7->setDisabled(1);
    ui->pushButton_8->setDisabled(1);

}


