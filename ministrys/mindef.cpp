#include "mindef.h"
#include "ui_mindef.h"

MinDef::MinDef(bool isBlocked, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MinDef)
{
    ui->setupUi(this);
    arg1 = -1;
    arg2 = -1;
    arg3 = -1;
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
    sendDataToMainForm(3,command,arg1,arg2,arg3);
    delete this;
}



void MinDef::on_pushButton_2_clicked()
{
    command = 1;
    arg1 = ui->spinBox->value();

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
    command = 2;
    arg1 = ui->spinBox_2->value();

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
    command = 3;
    arg1 = ui->spinBox_3->value();
    arg2 = ui->spinBox_4->value();
    arg3 = ui->spinBox_5->value();

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
    command = 4;
    arg1 = ui->spinBox_6->value();

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
    command = 5;
    arg1 = ui->spinBox_3->value();

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
    command = 6;
    arg1 = ui->spinBox_3->value();

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
    command = 7;
    arg1 = ui->spinBox_3->value();

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


