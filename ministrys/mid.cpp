#include "mid.h"
#include "ui_mid.h"
#include <QDebug>
#include <dialogs/pickthemin.h>
#include <ministrys/president.h>
#include <ministrys/minfin.h>
#include <ministrys/mindef.h>
#include <ministrys/kgb.h>
#include <ministrys/mid.h>
#include <ministrys/mvd.h>
#include <ministrys/minust.h>
#include <ministrys/mincom.h>
#include <ministrys/minhel.h>
#include <ministrys/secretary.h>

MID::MID(bool isBlocked, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::MID)
{
    verbMatrix = new bool*[countOfTeams];
    for(int i = 0; i< countOfTeams; i++)
    {
        verbMatrix[i] = new bool[10];
        for (int j = 0; j<10;j++)
            verbMatrix[i][j] = false;
    }

    c.args[0] = 5;

    ui->setupUi(this);


    ui->gerb->setPixmap(QPixmap("gerb.png"));

    if (isBlocked)
    {
        ui->diversionButton->setDisabled(true);
        ui->hookButton->setDisabled(true);
        ui->killButton->setDisabled(true);
        ui->spyButton->setDisabled(true);
    }

    int countOfAgents = 0;
    for (int i = 0;i<1;i++)
    {
        for (int j = 0; j<10; j++)
        {
            if (verbMatrix[i][j]) {countOfAgents++;}
        }
    }

    if (countOfAgents == 0)
    {
        ui->orderButton->setDisabled(true);
        ui->freeButton->setDisabled(true);
        ui->killButton->setDisabled(true);
    }
 }

MID::MID(MainWindow *its, bool isBlocked, int countOfTeams, bool **verbMatrix, QWidget *parent) :
    IMinister(parent),
    ui(new Ui::MID)
{
    parentForm = its;

    int countOfAgents = 0;
    if (countOfTeams > 0)
    {
    for (int i = 0;i<1;i++)
    {
        for (int j = 0; j<10; j++)
        {
            if (verbMatrix[i][j]) {countOfAgents++;}
        }
    }
    }

    this->countOfTeams = countOfTeams;
    this->verbMatrix = verbMatrix;
    c.args[0] = 5;

    ui->setupUi(this);
    if (this->countOfTeams != 0)
    ui->numOfCountrySpinBox->setMaximum(countOfTeams);


    ui->gerb->setPixmap(QPixmap("gerb.png"));

    if (countOfAgents == 0)
    {
        ui->orderButton->setDisabled(true);
        ui->freeButton->setDisabled(true);
        ui->killButton->setDisabled(true);
    }
    if (isBlocked)
    {
        ui->diversionButton->setDisabled(true);
        ui->hookButton->setDisabled(true);
        ui->killButton->setDisabled(true);
        ui->spyButton->setDisabled(true);
    }
}

MID::~MID()
{
    delete ui;
}

void MID::on_diversionButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(1,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    c.args[2] = ui->numOfCountrySpinBox->value();

    ui->hookButton->setDisabled(true);
    ui->freeButton->setDisabled(true);
    ui->orderButton->setDisabled(true);
    ui->killButton->setDisabled(true);
    ui->spyButton->setDisabled(true);
}

void MID::on_hookButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(2,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    c.args[2] = ui->numOfCountrySpinBox->value();




    ui->diversionButton->setDisabled(true);
    ui->freeButton->setDisabled(true);
    ui->orderButton->setDisabled(true);
    ui->killButton->setDisabled(true);
    ui->spyButton->setDisabled(true);
}

void MID::on_freeButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(3,c.args[2] = ui->numOfCountrySpinBox->value(), verbMatrix);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    c.args[2] = ui->numOfCountrySpinBox->value();



    ui->diversionButton->setDisabled(true);
    ui->hookButton->setDisabled(true);
    ui->orderButton->setDisabled(true);
    ui->killButton->setDisabled(true);
    ui->spyButton->setDisabled(true);
}

void MID::on_orderButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(4,c.args[2] = ui->numOfCountrySpinBox->value(), verbMatrix);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    c.args[2] = ui->numOfCountrySpinBox->value();
    orderFlag = true;



    ui->diversionButton->setDisabled(true);
    ui->freeButton->setDisabled(true);
    ui->hookButton->setDisabled(true);
    ui->killButton->setDisabled(true);
    ui->spyButton->setDisabled(true);
}

void MID::on_killButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(5,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    c.args[2] = ui->numOfCountrySpinBox->value();


    ui->diversionButton->setDisabled(true);
    ui->freeButton->setDisabled(true);
    ui->orderButton->setDisabled(true);
    ui->hookButton->setDisabled(true);
    ui->spyButton->setDisabled(true);
}

void MID::on_spyButton_clicked()
{
    PickTheMin *pickDial = new PickTheMin(6,0);
    connect(pickDial,SIGNAL(sendDataToParent(int,int)),this,SLOT(receiveDataFromDial(int,int)));
    pickDial->show();
    c.args[2] = ui->numOfCountrySpinBox->value();


    ui->diversionButton->setDisabled(true);
    ui->freeButton->setDisabled(true);
    ui->orderButton->setDisabled(true);
    ui->killButton->setDisabled(true);
    ui->hookButton->setDisabled(true);
}

void MID::on_approveButton_clicked()
{

    c.args[0] = 5;
    emit sendDataToMainForm(c);
    delete this;
}
void MID::receiveDataFromDial(int com,int choice)
{

    c.args[1] = com;
    c.args[3] = choice;
    if (orderFlag)
    {
        President *PresDial = new President(parentForm, false);
        MinFin *FinDial = new MinFin(parentForm,false);
        MinDef *defDial = new MinDef(parentForm,false);
        KGB *KGBDial = new KGB(parentForm,100, false);
        MID *MIDDial = new MID(false);
        MINUST *MINUSTDial = new MINUST(parentForm,false);
        MVD *MVDDial = new MVD(parentForm,false);
        MinCom *MinComDial = new MinCom(parentForm,false);
        MinHel *MinHelDial = new MinHel(parentForm,false);
        Secretary *SecretaryDial = new Secretary(parentForm);

        switch (choice)
        {
        case 1:
            connect(PresDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromMinForm(Command)));
            PresDial->show();
            break;
        case 2:
            connect(FinDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromMinForm(Command)));
            FinDial->show();
            break;
        case 3:
            connect(defDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromMinForm(Command)));
            defDial->show();
            break;
        case 4:
            connect(KGBDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromMinForm(Command)));
            KGBDial->show();
            break;
        case 5:
            connect(MIDDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromMinForm(Command)));
            MIDDial->show();
            break;
        case 6:
            connect(MINUSTDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromMinForm(Command)));
            MINUSTDial->show();
            break;
        case 7:
            connect(MVDDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromMinForm(Command)));
            MVDDial->show();
            break;
        case 8:
            connect(MinComDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromMinForm(Command)));
            MinComDial->show();
            break;
        case 9:
            connect(MinHelDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromMinForm(Command)));
            MinHelDial->show();
            break;
        case 10:
            connect(SecretaryDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromMinForm(Command)));
            SecretaryDial->show();
            break;
        }
    }

    ui->approveButton->setEnabled(true);
}

void MID::receivedFromMinForm(Command c2)
{
    c.args[4] = c2.args[1];
    c.args[5] = c2.args[2];
    c.args[6] = c2.args[3];
}


void MID::on_numOfCountrySpinBox_editingFinished()
{

}

void MID::on_numOfCountrySpinBox_valueChanged(int arg1)
{
    int countOfAgents = 0;

        for (int j = 0; j<10; j++)
        {
            if (verbMatrix[ui->numOfCountrySpinBox->value()-1][j]) {countOfAgents++;}
        }

    if (countOfAgents == 0)
    {
        ui->orderButton->setDisabled(true);
        ui->freeButton->setDisabled(true);
        ui->killButton->setDisabled(true);
    }
}
