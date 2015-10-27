#include "president.h"
#include "ui_president.h"
#include <dialogs/pickthemin.h>

President::President(bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::President)
{
    ui->setupUi(this);
    command = -1;
    arg1 = -1;
    arg2 = -1;
    arg3 = -1;

}

President::~President()
{
    delete ui;
}



void President::on_approveButton_clicked()
{
    sendDataToMainForm(1, command, arg1, arg2, arg3);
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
    command = com;
    arg1 = choice;
    ui->approveButton->setEnabled(true);

}
