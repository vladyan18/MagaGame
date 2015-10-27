#include "approved.h"
#include "ui_approved.h"

Approved::Approved(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Approved)
{
    ui->setupUi(this);
}

Approved::~Approved()
{
    delete ui;
}

void Approved::on_accept_clicked()
{
    delete this;
}
