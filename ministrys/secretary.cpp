#include "secretary.h"
#include "ui_secretary.h"
#include <dialogs/pickthemin.h>
#include <dialogs/helpdialog.h>

Secretary::Secretary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Secretary)
{
    ui->setupUi(this);
    role = -1;
    command = -1;
    arg1 = -1;
    arg2 = -1;
    arg3 = -1;

    ui->label->setPixmap(QPixmap("gerb.png").scaledToHeight(ui->label->height()));
}

Secretary::~Secretary()
{
    delete ui;
}


void Secretary::on_incLevelButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(0,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    ui->helpButton->setDisabled(true);
}

void Secretary::on_helpButton_clicked()
{
    HelpDialog *helpDial = new HelpDialog;
    connect(helpDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromHelpDial(int,int)));
    helpDial->show();
    ui->incLevelButton->setDisabled(true);
}

void Secretary::on_approveButton_clicked()
{
    sendDataToMainForm(role,command,arg1,arg2,arg3);
    delete this;
}


void Secretary::receiveDataFromDial(int com, int choice)
{
    role = choice;
    command = com;
    ui->approveButton->setEnabled(true);
}

void Secretary::receiveDataFromHelpDial(int helper, int receiver)
{
    role = helper;
    command = -2;
    arg1 = receiver;
    ui->approveButton->setEnabled(true);
}


