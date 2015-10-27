#include "connectdial.h"
#include "ui_connectdial.h"

ConnectDial::ConnectDial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDial)
{
    ui->setupUi(this);
}

ConnectDial::~ConnectDial()
{
    delete ui;
}

void ConnectDial::on_buttonBox_accepted()
{ int port;
    port = ui->portEdit->text().toInt();
    sendDataToMainForm(ui->hostEdit->text(), port);
    delete this;
}

void ConnectDial::on_buttonBox_rejected()
{
    delete this;
}
