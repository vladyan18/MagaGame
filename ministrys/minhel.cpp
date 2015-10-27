#include "minhel.h"
#include "ui_minhel.h"

MinHel::MinHel(bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MinHel)
{
    ui->setupUi(this);
    command = -1;
    arg1 = -1;
    arg2 = -1;
    arg3 = -1;
    ui->label_2->setPixmap(QPixmap("med.png"));
    ui->label_3->setToolTip("Больной вне опасности.");

    if (isBlocked)
    {
        ui->infectButton->setDisabled(true);
        ui->vaccineButton->setDisabled(true);
    }
}

MinHel::~MinHel()
{
    delete ui;
}

void MinHel::on_vaccineButton_clicked()
{
command = 1;
arg1 = ui->VirusSpinBox->value();

ui->approveButton->setEnabled(true);
ui->infectButton->setDisabled(true);
ui->infectSpinBox->setDisabled(true);
}

void MinHel::on_infectButton_clicked()
{
command = 2;
arg1 = ui->infectSpinBox->value();

ui->approveButton->setEnabled(true);
ui->vaccineButton->setDisabled(true);
ui->VirusSpinBox->setDisabled(true);
}

void MinHel::on_approveButton_clicked()
{
    emit sendDataToMainForm(9, command, arg1, arg2, arg3);
    delete this;
}


