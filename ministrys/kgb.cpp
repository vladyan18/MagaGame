#include "kgb.h"
#include "ui_kgb.h"
#include <dialogs/pickthemin.h>

KGB::KGB(MainWindow *its, int power,bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::KGB)
{
    ui->setupUi(this);

    ui->powerSpinBox->setMaximum(power);
    if (power == 0 )
    {
        ui->defRolesButton->setDisabled(true);
        ui->powerSpinBox->setDisabled(true);
    }

    if (isBlocked)
    {
        ui->findMinButton->setDisabled(true);
    }

    c.args[0] = 4;

    this->countOfTeams = its->countOfTeams;
    if (this->countOfTeams != 0)
    ui->numOfCountrySpinBox->setMaximum(this->countOfTeams);
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
    c.args[3] = ui->powerSpinBox->value();
    ui->findMinButton->setDisabled(true);
    ui->approveButton->setEnabled(true);

}

void KGB::on_findMinButton_clicked()
{
    c.args[1] = 2;
    c.args[2] = ui->numOfCountrySpinBox->value();

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





void KGB::on_powerSpinBox_editingFinished()
{
    ui->powerSpinBox->setValue(int(ui->powerSpinBox->value()/10)*10);
}
