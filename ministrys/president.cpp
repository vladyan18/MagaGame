#include "president.h"
#include "ui_president.h"
#include <dialogs/pickthemin.h>
#include <getnumdialog.h>

President::President(MainWindow *its, bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::President)
{
    ui->setupUi(this);
    c.args[0] = 1;
    this->countOfTeams = its->countOfTeams;
    this->countOfNukes = its->numNukes;
    this->countOfPRO = its->numPRO;
    this->its = its;
}

President::~President()
{
    delete ui;
}



void President::on_approveButton_clicked()
{
    sendDataToMainForm(c);
    delete this;
}

void President::on_fireMin_clicked()
{

        PickTheMin *pickDial = new PickTheMin(this,1,1);
        connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
        pickDial->exec();
        ui->approveButton->setEnabled(true);
}

void President::receiveDataFromDial(int com, int choice)
{
    c.args[1] = com;
    c.args[2] = choice;
}

void President::on_giveNukesButton_clicked()
{
    int temp;
    c.args[0] = 3;
    c.args[1] = 8;
    GetNumDialog *dial = new GetNumDialog(this,1,0,1,countOfTeams);
    this->setDisabled(true);
    dial->exec();
    temp = c.args[2];
    dial = new GetNumDialog(this, 2,0,1,countOfNukes);
    this->setDisabled(true);
    dial->exec();
    c.args[3] = c.args[2];
    c.args[2] = temp;
}

void President::on_givePROButton_clicked()
{
    int temp;
    c.args[0] = 3;
    c.args[1] = 9;
    GetNumDialog *dial = new GetNumDialog(this,1,0,1,countOfTeams);
    this->setDisabled(true);
    dial->exec();
    temp = c.args[2];
    dial = new GetNumDialog(this, 2,0,1,countOfPRO);
    this->setDisabled(true);
    dial->exec();
    c.args[3] = c.args[2];
    c.args[2] = temp;
}

void President::on_giveFacButton_clicked()
{

    int temp;
    c.args[0] = 2;
    c.args[1] = 4;
    GetNumDialog *dial = new GetNumDialog(this,1,0,1,countOfTeams);
    this->setDisabled(true);
    dial->exec();
    temp = c.args[2];

    PickTheMin *dial2 = new PickTheMin(this,4,0,2,0);
    dial2->exec();
    c.args[3] = c.args[2];
    c.args[2] = temp;

    switch(c.args[3])
    {
    case 1:
        dial = new GetNumDialog(this,6,0,1,its->profitSH);
        dial->exec();
        break;
    case 2:
        dial = new GetNumDialog(this,6,0,1,its->profitMS);
        dial->exec();
        break;
    case 3:
        dial = new GetNumDialog(this,6,0,1,its->profitTS);
        dial->exec();
        break;
    }

}
