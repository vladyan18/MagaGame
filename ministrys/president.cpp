#include "president.h"
#include "ui_president.h"
#include <dialogs/pickthemin.h>

President::President(MainWindow *its, bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::President)
{
    ui->setupUi(this);
    c.args[0] = 1;
    this->countOfTeams = its->countOfTeams;

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

        PickTheMin *pickDial = new PickTheMin(1,1);
        connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
        pickDial->show();
}

void President::receiveDataFromDial(int com, int choice)
{
    c.args[1] = com;
    c.args[2] = choice;
    ui->approveButton->setEnabled(true);

}
