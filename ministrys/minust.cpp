#include "minust.h"
#include "ui_minust.h"

MINUST::MINUST(bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MINUST)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap("gerb.png").scaledToHeight(ui->label->height()));

    if (isBlocked)
    {
        ui->goToCourtButton->setDisabled(true);
    }
}

MINUST::~MINUST()
{
    delete ui;
}

void MINUST::on_goToCourtButton_clicked()
{
    command = 1;
    arg1 = ui->numOfCountrySpinBox->value();

    ui->approveButton->setEnabled(true);
}

void MINUST::on_approveButton_clicked()
{
    emit sendDataToMainForm(6, command, arg1, arg2, arg3);
    delete this;
}


