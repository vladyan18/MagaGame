#include "kgb.h"
#include "ui_kgb.h"
#include <dialogs/pickthemin.h>
#include <getnumdialog.h>

KGB::KGB(MainWindow *its, int power,bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::KGB)
{
    ui->setupUi(this);

    kgbPower = power;

    if (isBlocked)
    {
        ui->findMinButton->setDisabled(true);
    }

    c.args[0] = 4;

    this->countOfTeams = its->countOfTeams;

}

KGB::~KGB()
{
    delete ui;
}

void KGB::on_defRolesButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(this,1,4);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->exec();

    GetNumDialog *dial = new GetNumDialog(this,7,0,10,this->kgbPower);
    dial->exec();
    ui->findMinButton->setDisabled(true);
    ui->approveButton->setEnabled(true);

}

void KGB::on_findMinButton_clicked()
{
    c.args[1] = 2;
    GetNumDialog *dial = new GetNumDialog(this,1,0,1,countOfTeams);
    dial->exec();

    ui->defRolesButton->setDisabled(true);
    ui->approveButton->setEnabled(true);
}

void KGB::receiveDataFromDial(int com,int choice)
{
}

void KGB::on_approveButton_clicked()
{
    emit sendDataToMainForm(c);
    delete this;
}
