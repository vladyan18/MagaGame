#include "mincom.h"
#include "ui_mincom.h"

MinCom::MinCom(MainWindow *its, bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::MinCom)
{
   ui->setupUi(this);
    c.args[0] = 8;
    ui->label_2->setPixmap(QPixmap("gerb.png").scaledToHeight(ui->label_2->height()));
    ui->label_3->setToolTip("Незнание - сила. \n Свобода - это рабство. \n Война - это мир.");
    ui->label_3->setToolTipDuration(10000);

    if (isBlocked)
    {
        ui->makeRiotButton->setDisabled(true);
        ui->refLiesButton->setDisabled(true);
        ui->sayToMediaButton->setDisabled(true);
    }

    this->countOfTeams = its->countOfTeams;
    if (this->countOfTeams != 0)
    ui->numOfCountrySpinBox->setMaximum(this->countOfTeams);
}

MinCom::~MinCom()
{
    delete ui;
}

void MinCom::on_approveButton_clicked()
{
    emit sendDataToMainForm(c);
    delete this;
}

void MinCom::on_sayToMediaButton_clicked()
{
    c.args[1] = 1;
    c.args[2] = ui->numOfCountrySpinBox->value();

    ui->refLiesButton->setDisabled(true);
    ui->improveMoodButton->setDisabled(true);
    ui->makeRiotButton->setDisabled(true);

    ui->approveButton->setEnabled(true);
}

void MinCom::on_refLiesButton_clicked()
{
    c.args[1] = 2;

    ui->sayToMediaButton->setDisabled(true);
    ui->improveMoodButton->setDisabled(true);
    ui->makeRiotButton->setDisabled(true);

    ui->approveButton->setEnabled(true);
}

void MinCom::on_improveMoodButton_clicked()
{
    c.args[1] = 3;

    ui->refLiesButton->setDisabled(true);
    ui->sayToMediaButton->setDisabled(true);
    ui->makeRiotButton->setDisabled(true);

    ui->approveButton->setEnabled(true);
}

void MinCom::on_makeRiotButton_clicked()
{
    c.args[1] = 4;
    c.args[2] = ui->numOfCountrySpinBox->value();

    ui->refLiesButton->setDisabled(true);
    ui->improveMoodButton->setDisabled(true);
    ui->sayToMediaButton->setDisabled(true);

    ui->approveButton->setEnabled(true);
}
