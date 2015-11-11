#include "secretary.h"
#include "ui_secretary.h"
#include <dialogs/pickthemin.h>
#include <dialogs/helpdialog.h>

Secretary::Secretary(MainWindow *its, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::Secretary)
{
    ui->setupUi(this);
    c.args[0] = 10;

    ui->label->setPixmap(QPixmap("gerb.png").scaledToHeight(ui->label->height()));
    this->countOfTeams = its->countOfTeams;
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
    sendDataToMainForm(c);
    delete this;
}


void Secretary::receiveDataFromDial(int com, int choice)
{
    c.args[0] = choice;
    c.args[1] = com;
    ui->approveButton->setEnabled(true);
}

void Secretary::receiveDataFromHelpDial(int helper, int receiver)
{
    c.args[0] = helper;
    c.args[1] = -2;
    c.args[2] = receiver;
    ui->approveButton->setEnabled(true);
}


