#include "minust.h"
#include "ui_minust.h"

MINUST::MINUST(MainWindow *its, bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::MINUST)
{
    ui->setupUi(this);
    c.args[0] = 6;
    if (isBlocked)
    {
        ui->goToCourtButton->setDisabled(true);
    }

    this->countOfTeams = its->countOfTeams;
    if (this->countOfTeams != 0)
    ui->numOfCountrySpinBox->setMaximum(this->countOfTeams);
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


