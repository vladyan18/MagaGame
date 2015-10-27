#include "mincom.h"
#include "ui_mincom.h"

MinCom::MinCom(bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MinCom)
{
   ui->setupUi(this);
    command = -1;
    arg1 = -1;
    arg2 = -1;
    arg3 = -1;
    ui->label_2->setPixmap(QPixmap("gerb.png").scaledToHeight(ui->label_2->height()));
    ui->label_3->setToolTip("Незнание - сила. \n Свобода - это рабство. \n Война - это мир.");
    ui->label_3->setToolTipDuration(10000);

    if (isBlocked)
    {
        ui->makeRiotButton->setDisabled(true);
        ui->refLiesButton->setDisabled(true);
        ui->sayToMediaButton->setDisabled(true);
    }
}

MinCom::~MinCom()
{
    delete ui;
}

void MinCom::on_approveButton_clicked()
{
    emit sendDataToMainForm(8, command, arg1,arg2,arg3);
    delete this;
}

void MinCom::on_sayToMediaButton_clicked()
{
    command = 1;
    arg1 = ui->numOfCountrySpinBox->value();

    ui->refLiesButton->setDisabled(true);
    ui->improveMoodButton->setDisabled(true);
    ui->makeRiotButton->setDisabled(true);

    ui->approveButton->setEnabled(true);
}

void MinCom::on_refLiesButton_clicked()
{
    command = 2;

    ui->sayToMediaButton->setDisabled(true);
    ui->improveMoodButton->setDisabled(true);
    ui->makeRiotButton->setDisabled(true);

    ui->approveButton->setEnabled(true);
}

void MinCom::on_improveMoodButton_clicked()
{
    command = 3;

    ui->refLiesButton->setDisabled(true);
    ui->sayToMediaButton->setDisabled(true);
    ui->makeRiotButton->setDisabled(true);

    ui->approveButton->setEnabled(true);
}

void MinCom::on_makeRiotButton_clicked()
{
    command = 4;
    arg1 = ui->numOfCountrySpinBox->value();

    ui->refLiesButton->setDisabled(true);
    ui->improveMoodButton->setDisabled(true);
    ui->sayToMediaButton->setDisabled(true);

    ui->approveButton->setEnabled(true);
}
