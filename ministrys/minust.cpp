#include "minust.h"
#include "ui_minust.h"

MINUST::MINUST(bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MINUST)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap("gerb.png").scaledToHeight(ui->label->height()));
    c.args[0] = 6;
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
    c.args[1] = 1;
    c.args[2] = ui->numOfCountrySpinBox->value();

    ui->approveButton->setEnabled(true);
}

void MINUST::on_approveButton_clicked()
{
    emit sendDataToMainForm(c);
    delete this;
}


