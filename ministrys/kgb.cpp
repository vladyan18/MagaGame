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

    if (isBlocked)
    {
        ui->findMinButton->setDisabled(true);
    }

    c.args[0] = 4;

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
    c.args[1] = 2;
    c.args[2] = ui->numOfCountrySpinBox->value();

    ui->defRolesButton->setDisabled(true);
    ui->approveButton->setEnabled(true);
}

void KGB::receiveDataFromDial(int com,int choice)
{
    c.args[1] = com;
    c.args[2] = choice;
    c.args[3] = ui->powerSpinBox->value();
    ui->findMinButton->setDisabled(true);
    ui->approveButton->setEnabled(true);

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
