#include "kgb.h"
#include "ui_kgb.h"
#include <dialogs/pickthemin.h>

KGB::KGB(int power,bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KGB)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap("kgb.png"));

    ui->powerSpinBox->setMaximum(power);
    if (power == 0 )
    {
        ui->defRolesButton->setDisabled(true);
        ui->powerSpinBox->setDisabled(true);
    }

    command = -1;
    arg1 = -1;
    arg2 = -1;
    arg3 = -1;

    if (isBlocked)
    {
        ui->findMinButton->setDisabled(true);
    }


}

KGB::~KGB()
{
    delete ui;
}

void KGB::on_defRolesButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(1,4);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();


}

void KGB::on_findMinButton_clicked()
{
    command = 2;
    arg1 = ui->numOfCountrySpinBox->value();

    ui->defRolesButton->setDisabled(true);
    ui->approveButton->setEnabled(true);
}

void KGB::receiveDataFromDial(int com,int choice)
{
    command = com;
    arg1 = choice;
    arg2 = ui->powerSpinBox->value();
    ui->findMinButton->setDisabled(true);
    ui->approveButton->setEnabled(true);

}

void KGB::on_approveButton_clicked()
{
    emit sendDataToMainForm(4,command,arg1,arg2,arg3);
    delete this;
}





void KGB::on_powerSpinBox_editingFinished()
{
    ui->powerSpinBox->setValue(int(ui->powerSpinBox->value()/10)*10);
}
