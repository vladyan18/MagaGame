#include "getnumdialog.h"
#include "ui_getnumdialog.h"
#include <ministrys/iminister.h>


GetNumDialog::GetNumDialog(IMinister *prnt, int mode, int min, int max, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetNumDialog)
{
    ui->setupUi(this);
    this->prnt = prnt;
    this->mode = mode;



    switch (mode)
    {
    case 1:
        ui->label->setText("Выберите страну:");
        this->setWindowTitle("Выбор страны");
        break;
    case 2:
        ui->label->setText("Введите количество ракет:");
        this->setWindowTitle("Выбор количества ракет");
        break;
    case 3:
        ui->label->setText("Введите количество ракет:");
        this->setWindowTitle("Выбор количества ракет для ядерного удара");
        break;
    case 4:
        ui->label->setText("Введите сумму денег:");
        this->setWindowTitle("Выбор суммы денег");
        break;
    case 5:
        ui->label->setText("Прогноз на курс (-100, 100)");
        this->setWindowTitle("Выбор прогнозируемого курса");
        break;
    }

    if (max >= min)
    {
    ui->spinBox->setMaximum(max);
    ui->spinBox->setMinimum(min);
    }
    else
    {
        prnt->c.args[0] = -1;
        prnt->c.args[1] = -1;
        ui->spinBox->setValue(-1);
        ui->spinBox->setDisabled(true);
    }

    if (max == 0)
    {
        prnt->c.args[0] = -1;
        prnt->c.args[1] = -1;
        ui->spinBox->setValue(-1);
        ui->spinBox->setDisabled(true);
    }
}

GetNumDialog::~GetNumDialog()
{
    if (prnt != NULL)
    prnt->setEnabled(true);
    delete ui;
}


void GetNumDialog::on_pushButton_clicked()
{
    if (prnt != NULL)
    {
    switch (mode)
    {
    case 1:
        prnt->c.args[2] = ui->spinBox->value();
        break;
    case 2:
        prnt->c.args[2] = ui->spinBox->value();
        break;
    case 3:
        prnt->c.args[3] = ui->spinBox->value();
        break;
    case 4:
        prnt->c.args[3] = ui->spinBox->value();
        break;
    case 5:
        prnt->c.args[2] = ui->spinBox->value();
    }
    prnt->setEnabled(true);
    }

    delete this;
}

void GetNumDialog::on_GetNumDialog_destroyed()
{
}

void GetNumDialog::on_GetNumDialog_finished(int result)
{
    if (prnt != NULL)
    prnt->c.args[0] = -1;
    prnt->c.args[1] = -1;
    prnt->setEnabled(true);
}