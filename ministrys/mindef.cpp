#include "mindef.h"
#include "ui_mindef.h"

MinDef::MinDef(bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MinDef)
{
    ui->setupUi(this);
    c.args[0] = 3;
    ui->label_2->setPixmap(QPixmap("star.png").scaledToHeight(ui->label_2->height()));

    if (isBlocked)
    {

    }
}

MinDef::~MinDef()
{
    delete ui;
}

void MinDef::on_pushButton_clicked()
{
    // 3 - номер роли
    sendDataToMainForm(c);
    delete this;
}



void MinDef::on_pushButton_2_clicked()
{
    c.args[1] = 1;
    c.args[2] = ui->spinBox->value();

    ui->pushButton_3->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_7->setDisabled(1);
    ui->pushButton_8->setDisabled(1);

    ui->spinBox_2->setDisabled(1);
    ui->spinBox_3->setDisabled(1);
    ui->spinBox_4->setDisabled(1);
    ui->spinBox_5->setDisabled(1);
    ui->spinBox_6->setDisabled(1);
}

void MinDef::on_pushButton_3_clicked()
{
    c.args[1] = 2;
    c.args[2] = ui->spinBox_2->value();

    ui->pushButton_2->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_7->setDisabled(1);
    ui->pushButton_8->setDisabled(1);

    ui->spinBox->setDisabled(1);
    ui->spinBox_3->setDisabled(1);
    ui->spinBox_4->setDisabled(1);
    ui->spinBox_5->setDisabled(1);
    ui->spinBox_6->setDisabled(1);
}



void MinDef::on_pushButton_7_clicked()
{
    c.args[1] = 3;
    c.args[2] = ui->spinBox_3->value();
    c.args[3] = ui->spinBox_4->value();
    c.args[4] = ui->spinBox_5->value();

    ui->pushButton_2->setDisabled(1);
    ui->pushButton_3->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_8->setDisabled(1);

    ui->spinBox_2->setDisabled(1);
    ui->spinBox->setDisabled(1);
    ui->spinBox_6->setDisabled(1);

}

void MinDef::on_pushButton_4_clicked()
{
    c.args[1] = 4;
    c.args[2] = ui->spinBox_6->value();

    ui->pushButton_2->setDisabled(1);
    ui->pushButton_3->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_7->setDisabled(1);
    ui->pushButton_8->setDisabled(1);

    ui->spinBox_2->setDisabled(1);
    ui->spinBox_3->setDisabled(1);
    ui->spinBox_4->setDisabled(1);
    ui->spinBox_5->setDisabled(1);
    ui->spinBox->setDisabled(1);
}

void MinDef::on_pushButton_8_clicked()
{
    c.args[1] = 5;
    c.args[2] = ui->spinBox_3->value();

    ui->pushButton_2->setDisabled(1);
    ui->pushButton_3->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_7->setDisabled(1);

    ui->spinBox_2->setDisabled(1);
    ui->spinBox->setDisabled(1);
    ui->spinBox_4->setDisabled(1);
    ui->spinBox_5->setDisabled(1);
    ui->spinBox_6->setDisabled(1);
}

void MinDef::on_pushButton_6_clicked()
{
    c.args[1] = 6;
    c.args[2] = ui->spinBox_3->value();

    ui->pushButton_2->setDisabled(1);
    ui->pushButton_3->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_5->setDisabled(1);
    ui->pushButton_7->setDisabled(1);
    ui->pushButton_8->setDisabled(1);

    ui->spinBox_2->setDisabled(1);
    ui->spinBox->setDisabled(1);
    ui->spinBox_4->setDisabled(1);
    ui->spinBox_5->setDisabled(1);
    ui->spinBox_6->setDisabled(1);
}

void MinDef::on_pushButton_5_clicked()
{
    c.args[1] = 7;
    c.args[2] = ui->spinBox_3->value();

    ui->pushButton_2->setDisabled(1);
    ui->pushButton_3->setDisabled(1);
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_6->setDisabled(1);
    ui->pushButton_7->setDisabled(1);
    ui->pushButton_8->setDisabled(1);

    ui->spinBox_2->setDisabled(1);
    ui->spinBox->setDisabled(1);
    ui->spinBox_4->setDisabled(1);
    ui->spinBox_5->setDisabled(1);
    ui->spinBox_6->setDisabled(1);
}


