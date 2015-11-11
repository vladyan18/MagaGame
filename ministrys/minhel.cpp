#include "minhel.h"
#include "ui_minhel.h"

MinHel::MinHel(MainWindow *its, bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::MinHel)
{
    ui->setupUi(this);
    c.args[0] = 9;
    ui->label_2->setPixmap(QPixmap("med.png"));
    ui->label_3->setToolTip("Больной вне опасности.");

    if (isBlocked)
    {
        ui->infectButton->setDisabled(true);
        ui->vaccineButton->setDisabled(true);
    }

    this->countOfTeams = its->countOfTeams;
    if (this->countOfTeams != 0)
    {
    ui->infectSpinBox->setMaximum(this->countOfTeams);
    ui->VirusSpinBox->setMaximum(this->countOfTeams);
    }
}

MinHel::~MinHel()
{
    delete ui;
}

void MinHel::on_vaccineButton_clicked()
{
    c.args[1] = 1;
    c.args[2] = ui->VirusSpinBox->value();

ui->approveButton->setEnabled(true);
ui->infectButton->setDisabled(true);
ui->infectSpinBox->setDisabled(true);
}

void MinHel::on_infectButton_clicked()
{
    c.args[1] = 2;
    c.args[2] = ui->infectSpinBox->value();

ui->approveButton->setEnabled(true);
ui->vaccineButton->setDisabled(true);
ui->VirusSpinBox->setDisabled(true);
}

void MinHel::on_approveButton_clicked()
{
    emit sendDataToMainForm(c);
    delete this;
}


