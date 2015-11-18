#include "secretary.h"
#include "ui_secretary.h"
#include <dialogs/pickthemin.h>
#include <dialogs/helpdialog.h>
#include <getnumdialog.h>

Secretary::Secretary(MainWindow *its, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::Secretary)
{
    ui->setupUi(this);
    c.args[0] = 10;
    this->countOfTeams = its->countOfTeams;
}

Secretary::~Secretary()
{
    delete ui;
}


void Secretary::on_incLevelButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(this,0,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->exec();
    c.args[0] = c.args[2];
    c.args[2] = -1;
    ui->approveButton->setEnabled(true);
    ui->helpButton->setDisabled(true);
}

void Secretary::on_helpButton_clicked()
{
    GetNumDialog *dial = new GetNumDialog(this,1,0,1,this->countOfTeams);
    dial->exec();
    c.args[3] = c.args[2];

    HelpDialog *helpDial = new HelpDialog;
    connect(helpDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromHelpDial(int,int)));
    helpDial->exec();
    ui->incLevelButton->setDisabled(true);
}

void Secretary::on_approveButton_clicked()
{
    sendDataToMainForm(c);
    delete this;
}


void Secretary::receiveDataFromDial(int com, int choice)
{
}

void Secretary::receiveDataFromHelpDial(int helper, int receiver)
{
    c.args[0] = helper;
    c.args[1] = -2;
    c.args[2] = receiver;
    ui->approveButton->setEnabled(true);
}


