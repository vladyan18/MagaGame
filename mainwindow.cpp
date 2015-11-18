#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <dialogs/approved.h>
#include <dialogs/connectdial.h>
#include <dialogs/helpdialog.h>
#include <dialogs/pickthemin.h>
#include <dialogs/report.h>
#include <dialogs/statistic.h>
#include <tools/nettransmitter.h>
#include <QFile>
#include <QTextStream>
#include <QtNetwork>
#include <QDebug>
#include <QByteArray>

#define COST_OF_NUKE_CREATION    2000000
#define COST_OF_NUKE_DESTRUCTION 100000
#define COST_OF_PRO_CREATION     1000000
#define COST_OF_PRO_DESTRUCTION  100000
#define COST_OF_ROCKET_KEEPING   50000
#define COST_OF_INVESTMENT       2000000
#define COST_OF_RAID             500000
#define COST_OF_FINDING_MINISTER 3000000
#define COST_OF_MINISTER_DEFENCE 1000000
#define COST_OF_DIVERSION        1500000
#define COST_OF_HOOKING          3000000
#define COST_OF_KILLING          3000000
#define COST_OF_SPY              2000000
#define COST_OF_COURT            1000000
#define COST_OF_SUPRESSION       500000
#define COST_OF_CHECK_MIN        500000
#define COST_OF_AREST            1500000
#define COST_OF_CLAIM            1000000
#define COST_OF_REFUTATION       500000
#define COST_OF_PROPOGANDA       500000
#define COST_OF_INC_RIOT         500000
#define COST_OF_VACIINE          250000
#define COST_OF_INFECT           1000000
#define COST_OF_LVLUP            1000000
#define COST_OF_HELP             500000

void MainWindow::addToList(int row, List *lt){
    ui->listWidget->insertItem(row, lt->text);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    transmitter = new NetTransmitter(this);
    namesOfMins = new QString[10] {"президента", "министра финансов", "министра обороны", "главы КГБ",
                        "министра иностранных дел", "министра юстиции", "министра внутренних дел",
                        "министра по связям с общественностью", "министра здравоохранения", "заместителя"};
    listSize = 20;
    cmds = new List[listSize];
    repDial = new Report();
    connect (repDial, SIGNAL(loose()), this, SLOT(loose()));

    kgbpower = 100;
    profitSH = 1000000;
    profitMS = 1000000;
    profitTS = 1000000;
    cash = 0;
    numNukes = 0;
    numPRO = 0;
    happinesOfPopulation = 100;

    makeBudget();

    clearList();
    updateList();

    ui->listWidget->setCurrentRow(0);




}

MainWindow::~MainWindow()
{
    delete repDial;
    delete ui;
}

void MainWindow::on_presidentButton_clicked()
{
President *PresDial = new President(this, mins[0].isBlocked);
connect(PresDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromForm(Command)));
PresDial->exec();
}

void MainWindow::on_minFinButton_clicked()
{
MinFin *FinDial = new MinFin(this, mins[1].isBlocked);
connect(FinDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromForm(Command)));
FinDial->exec();

}

void MainWindow::on_minDefButton_clicked()
{
MinDef *defDial = new MinDef(this, mins[2].isBlocked);
connect(defDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromForm(Command)));
defDial->exec();
}

void MainWindow::on_kgbButton_clicked()
{
KGB *KGBDial = new KGB(this, kgbpower, mins[3].isBlocked);
connect(KGBDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromForm(Command)));
KGBDial->exec();
}

void MainWindow::on_midButton_clicked()
{
MID *MIDDial = new MID(this, mins[4].isBlocked,countOfTeams, verbedMatrix);
connect(MIDDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromForm(Command)));
MIDDial->exec();
}

void MainWindow::on_minUstButton_clicked()
{
MINUST *MINUSTDial = new MINUST(this, mins[5].isBlocked);
connect(MINUSTDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromForm(Command)));
MINUSTDial->exec();
}

void MainWindow::on_mvdButton_clicked()
{
MVD *MVDDial = new MVD(this, mins[6].isBlocked);
connect(MVDDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromForm(Command)));
MVDDial->exec();
}

void MainWindow::on_minComButton_clicked()
{
MinCom *MinComDial = new MinCom(this, mins[7].isBlocked);
connect(MinComDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromForm(Command)));
MinComDial->exec();
}

void MainWindow::on_minHelButton_clicked()
{
MinHel *MinHelDial = new MinHel(this, mins[8].isBlocked);
connect(MinHelDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromForm(Command)));
MinHelDial->exec();
}


void MainWindow::on_secretaryButton_clicked()
{
Secretary *SecretaryDial = new Secretary(this);
connect(SecretaryDial,SIGNAL(sendDataToMainForm(Command)),this,SLOT(receivedFromForm(Command)));
SecretaryDial->exec();
}

void MainWindow::on_reportButton_clicked()
{
    repDial->show();
}

void MainWindow::on_statButton_clicked()
{
    Statistic *stat = new Statistic(this);
    stat->show();
}

void MainWindow::receivedFromForm(Command c)
{
    switch (c.args[0]) {
    case 1: //Президент
        presidentSaid(c);
        break;
    case 2: //Министр финансов
        minFinSaid(c);
        break;
    case 3: //Министр обороны
        minDefSaid(c);
        break;
    case 4: //Директор КГБ
        KGBSaid(c);
        break;
    case 5: //Министр иностранных дел
        midSaid(c);
        break;
    case 6: //Министр юстиции
        minUstSaid(c);
        break;
    case 7: //Министр Внутренних Дел
        MVDSaid(c);
        break;
    case 8: //Министр по связям с общ
        minComSaid(c);
        break;
    case 9: //Министр здравоохранения
        minHelSaid(c);
        break;
    case 10: //Заместитель
        zamSaid(c);
        break;
    }
}

void MainWindow::updateList()
{
    checkBlocks();
    kgbpower = 100;
    int *row = new int;
    *row = ui->listWidget->currentRow();
    ui->listWidget->clear();
    for (int i = 0; i<listSize;i++) {
        addToList(i,&cmds[i]);
        if ((cmds[i].role == 4)&&(cmds[i].command == 1))
            {
            kgbpower -= cmds[i].arg[1];
            }
    }
ui->listWidget->setCurrentRow(*row);
    makeBudget();
    delete row;

}

void MainWindow::clearList()
{
    for (int i = 0; i<listSize;i++) {
        cmds[i].text = QString::number(i+1) + ":";
        cmds[i].role = -1;
        cmds[i].command = -1;
        cmds[i].arg[0] = -1;
        cmds[i].arg[1] = -1;
        cmds[i].arg[2] = -1;
        cmds[i].arg[3] = -1;
        cmds[i].arg[4] = -1;
        cmds[i].cost=0;
    }

}

void MainWindow::makeBudget()
{
    int *money = new int;
    *money = 0;
    *money += profitMS;
    *money += profitSH;
    *money += profitTS;

    *money -= numNukes * COST_OF_ROCKET_KEEPING;
    *money -= numPRO * COST_OF_ROCKET_KEEPING;

    for (int i=0;i<listSize;i++)
    {
     *money -= cmds[i].cost;
    }

    if (*money<0) {
        ui->budget->setStyleSheet("color:red;");
        ui->budget->setText("Дефицит бюджета: " + beautifyNumber(*money));
    } else {
        ui->budget->setStyleSheet("color:green;");
        ui->budget->setText("Профицит бюджета: " + beautifyNumber(*money));
    }

    delete money;
}

void MainWindow::checkBlocks()
{
    for (int i=0; i<10; i++)
    {
        mins[i].isBlocked = false;
    }

    for (int i = 0; i<listSize;i++)
    {
        switch (cmds[i].role)
        {
        case 1:
            switch (cmds[i].command)
            {
            case -2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 0:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            }
            break;
        case 2:
            switch (cmds[i].command)
            {
            case -2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 0:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 1:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            }

            break;
        case 3:
            switch (cmds[i].command)
            {
            case -2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 0:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 3:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 4:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 6:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 7:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            }
            break;
        case 4:
            switch (cmds[i].command)
            {
            case -2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 0:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            }
            break;
        case 5:
            switch (cmds[i].command)
            {
            case -2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 0:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 1:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 5:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 6:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            }
            break;
        case 6:
            switch (cmds[i].command)
            {
            case -2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 0:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 1:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            }
            break;
        case 7:
            switch (cmds[i].command)
            {
            case -2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 0:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 3:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            }
            break;
        case 8:
            switch (cmds[i].command)
            {
            case -2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 0:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 1:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 4:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            }
            break;
        case 9:
            switch (cmds[i].command)
            {
            case -2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 0:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 1:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            case 2:
                mins[cmds[i].role - 1].isBlocked = true;
                break;
            }
            break;

        }
    }
}

void MainWindow::on_listWidget_itemDoubleClicked()
{


    int *row = new int;
    *row = ui->listWidget->currentRow();
    cmds[*row].text = QString::number(*row+1) + ":";
    cmds[*row].role = -1;
    cmds[*row].command = -1;
    cmds[*row].arg[0] = -1;
    cmds[*row].arg[1] = -1;
    cmds[*row].arg[2] = -1;
    cmds[*row].arg[3] = -1;
    cmds[*row].arg[4] = -1;
    cmds[*row].cost = 0;
    updateList();
    delete row;
}

void MainWindow::presidentSaid(Command c)
{
    int *row = new int;
    *row = ui->listWidget->currentRow();
    cmds[*row].role = 1;
    cmds[*row].command = c.args[1];


    switch (c.args[1])
    {
    case 0:
        cmds[*row].text = QString::number(*row+1) +": Повышение квалификации " + namesOfMins[cmds[*row].role-1];
        cmds[*row].cost= COST_OF_LVLUP;
        break;
    case 1:
        cmds[*row].text = QString::number(*row+1) +": Увольнение " + namesOfMins[c.args[2] - 1];
        cmds[*row].arg[0]=c.args[2];
        cmds[*row].cost=0;
        break;

    case -2:
        cmds[*row].text = QString::number(*row+1) +": Оказание помощи президентом в делах " + namesOfMins[c.args[2] - 1];
        if (c.args[3] != this->numTeam)
        {
            cmds[*row].text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds[*row].arg[0]=c.args[2];
        cmds[*row].arg[1]=c.args[3];
        cmds[*row].cost=COST_OF_HELP;
        break;
    }
    updateList();
    if (ui->listWidget->currentRow() != listSize - 1)
    {
    ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
    }
    delete row;

}

void MainWindow::minFinSaid(Command c)
{
    int *row = new int;
    *row = ui->listWidget->currentRow();
    cmds[*row].role = 2;
    cmds[*row].command = c.args[1];

    switch(c.args[1]) {
    case 0:
        cmds[*row].text = QString::number(*row+1) +": Повышение квалификации министра финансов";
        cmds[*row].cost= COST_OF_LVLUP;
        break;
    case 1:
        cmds[*row].text = QString::number(*row+1) +": Инвестиции в сектора экономики:  ";
       switch (c.args[2])
       {
       case 1:
           cmds[*row].text += "сельское хозяйство, ";
           switch (c.args[3])
           {
           case 2:
               cmds[*row].text += "тяжелая промышленность ";
               break;
           case 3:
               cmds[*row].text += "легкая промышленность ";
               break;
           }

           break;
       case 2:
               cmds[*row].text += "тяжелая промышленность, ";
               switch(c.args[3])
               {
               case 1:
                   cmds[*row].text += "сельское хозяйство" ;
                   break;
               case 3:
                   cmds[*row].text += "легкая промышленность ";
                   break;
               }
           break;
       case 3:
                   cmds[*row].text += "легкая промышленность, ";
                   switch(c.args[3])
                   {
                   case 1:
                       cmds[*row].text += "сельское хозяйство ";
                       break;
                   case 2:
                       cmds[*row].text += "тяжелая промышленность ";
                       break;
                   }

           break;
       }

        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        cmds[*row].cost = COST_OF_INVESTMENT;
        break;
    case 2:
        cmds[*row].text = QString::number(*row+1) +": Игра на бирже, ставка: " + QString::number(c.args[3])
                + ", цена: " + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        cmds[*row].cost = c.args[3];
        break;
    case 3:
        cmds[*row].text = QString::number(*row+1) +": Транш суммы: " + QString::number(c.args[3])
                + " в государство: " + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        cmds[*row].cost = c.args[3];
        break;
    case 4:
        cmds[*row].text = QString::number(*row+1) +": Передача стране №" + QString::number(c.args[2]) + " производственных мощностей ";
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        cmds[*row].arg[2] = c.args[4];
        switch (c.args[3])
        {
        case 1:
            cmds[*row].text +="сельского хозяйства";
            break;
        case 2:
            cmds[*row].text +="тяжелой промышленности";
            break;
        case 3:
            cmds[*row].text +="легкой промышленности";
            break;
        }
        cmds[*row].text += " в размере " + QString::number(c.args[4]);

        break;
    case -2:
        cmds[*row].text = QString::number(*row+1) +": Оказание помощи министром финансов в делах " + namesOfMins[c.args[2] - 1];
        if (c.args[3] != this->numTeam)
        {
            cmds[*row].text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds[*row].arg[0]=c.args[2];
        cmds[*row].arg[1]=c.args[3];
        cmds[*row].cost=COST_OF_HELP;
        break;
    }
   updateList();
   if (ui->listWidget->currentRow() != listSize - 1)
   {
   ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
   }
   delete row;
}

void MainWindow::minDefSaid(Command c)
{
    int *row = new int;
    *row = ui->listWidget->currentRow();
    cmds[*row].role = 3;
    cmds[*row].command = c.args[1];
    switch (c.args[1]) {
    case 0:
        cmds[*row].text = QString::number(*row+1) +": Повышение квалификации министра обороны";
        cmds[*row].cost= COST_OF_LVLUP;
        break;
    case 1:
        cmds[*row].text = QString::number(*row+1) +": Изменение числа ядерных ракет " + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];

        if (c.args[2]>0)
        {
            cmds[*row].cost = abs(c.args[2]) * COST_OF_NUKE_CREATION;
        } else {
            cmds[*row].cost = abs(c.args[2]) * COST_OF_NUKE_DESTRUCTION;
        }

        break;
    case 2:
        cmds[*row].text = QString::number(*row+1) +": Изменение числа ПРО " + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];

        if (c.args[2] > 0)
        {
            cmds[*row].cost = abs(c.args[2]) * COST_OF_PRO_CREATION;
        } else {
            cmds[*row].cost = abs(c.args[2]) * COST_OF_PRO_DESTRUCTION;
        }
        break;
    case 3:
        cmds[*row].text = QString::number(*row+1) +": НАНЕСЕНИЕ ЯДЕРНОГО УДАРА ПО СТРАНЕ №" + QString::number(c.args[2])
                + " число ракет:" + QString::number(c.args[3]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        break;
    case 4:
        cmds[*row].text = QString::number(*row+1) +": Сбить ядерную ракету. Число противоракет:" + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        break;
    case 5:
        cmds[*row].text = QString::number(*row+1) +": Отмена ядерного удара по стране №" + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        break;
    case 6:
        cmds[*row].text = QString::number(*row+1) +": Атака сухопутными силами на страну №" + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        break;
    case 7:
        cmds[*row].text = QString::number(*row+1) +": Набег на страну №" + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].cost = COST_OF_RAID;
        break;
    case 8:
        cmds[*row].text = QString::number(*row+1) +": Передача ядерных ракет стране №" + QString::number(c.args[2]) + ", в количестве " + QString::number(c.args[3]) + " единиц";
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        break;
    case 9:
        cmds[*row].text = QString::number(*row+1) +": Передача ракет ПРО стране №" + QString::number(c.args[2]) + ", в количестве " + QString::number(c.args[3]) + " единиц";
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        break;
    case -2:
        cmds[*row].text = QString::number(*row+1) +": Оказание помощи министром обороны в делах " + namesOfMins[c.args[2] - 1];
        if (c.args[3] != this->numTeam)
        {
            cmds[*row].text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds[*row].arg[0]=c.args[2];
        cmds[*row].arg[1]=c.args[3];
        cmds[*row].cost=COST_OF_HELP;
        break;
    }
   updateList();
   if (ui->listWidget->currentRow() != listSize - 1)
   {
   ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
   }
   delete row;
}

void MainWindow::KGBSaid(Command c)
{
    int *row = new int;
    *row = ui->listWidget->currentRow();
    cmds[*row].role = 4;
    cmds[*row].command = c.args[1];
    switch(c.args[1]) {
    case 0:
        cmds[*row].text = QString::number(*row+1) +": Повышение квалификации главы КГБ";
        cmds[*row].cost= COST_OF_LVLUP;
        break;
    case 1:
        cmds[*row].text = QString::number(*row+1) +": Защита " + namesOfMins[c.args[2]-1] + " от иностранного воздействия с силой: "
              + QString::number(c.args[3]) + "%";
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        cmds[*row].cost = COST_OF_MINISTER_DEFENCE;
        kgbpower -= c.args[3];
        break;
    case 2:
        cmds[*row].text = QString::number(*row+1) +": Поиск министра внешней разведки государства №" + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].cost = COST_OF_FINDING_MINISTER;
        break;
    case -2:
        cmds[*row].text = QString::number(*row+1) +": Оказание главой КГБ в делах " + namesOfMins[c.args[2] - 1];
        if (c.args[3] != this->numTeam)
        {
            cmds[*row].text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds[*row].arg[0]=c.args[2];
        cmds[*row].arg[1]=c.args[3];
        cmds[*row].cost=COST_OF_HELP;
        break;
    }
    updateList();
    if (ui->listWidget->currentRow() != listSize - 1)
    {
    ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
    }
    delete row;
}

void MainWindow::midSaid(Command c)
{
    int *row = new int;
    *row = ui->listWidget->currentRow();
    cmds[*row].role = 5;
    cmds[*row].command = c.args[1];

    switch (c.args[1])
    {
    case 0:
        cmds[*row].text = QString::number(*row+1) +": Повышение квалификации министра иностранных дел";
        cmds[*row].cost= COST_OF_LVLUP;
        break;
    case 1:
        cmds[*row].text = QString::number(*row+1) +": Диверсия в государстве №" + QString::number(c.args[2]) + " в делах  "
                + namesOfMins[c.args[3]-1];
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        cmds[*row].cost = COST_OF_DIVERSION;
        break;
    case 2:
        cmds[*row].text = QString::number(*row+1) +": Вербовка " + namesOfMins[c.args[3]-1] + " в государстве №"
                + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        cmds[*row].cost = COST_OF_HOOKING;
        break;
    case 3:
        cmds[*row].text = QString::number(*row+1) +": Освобождение " + namesOfMins[c.args[3]-1] + " в государстве №"
                + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        cmds[*row].cost = 0;
        break;
    case 4:
        cmds[*row].text = QString::number(*row+1) +": Приказ министру №" + QString::number(c.args[3]) + " в государстве №"
                + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        cmds[*row].arg[2] = c.args[4];
        cmds[*row].arg[3] = c.args[5];
        cmds[*row].arg[4] = c.args[6];
        cmds[*row].cost = 0;
        break;
    case 5:
        cmds[*row].text = QString::number(*row+1) +": Убить " + namesOfMins[c.args[3]-1]  + " в государстве №"
                + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        cmds[*row].cost = COST_OF_KILLING;
        break;
    case 6:
        cmds[*row].text = QString::number(*row+1) +": Шпионаж за делами " + namesOfMins[c.args[3]-1] + " в государстве №"
                + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].arg[1] = c.args[3];
        cmds[*row].cost = COST_OF_SPY;
        break;
    case -2:
        cmds[*row].text = QString::number(*row+1) +": Оказание помощи министром иностранных дел в делах " + namesOfMins[c.args[2] - 1];
        if (c.args[3] != this->numTeam)
        {
            cmds[*row].text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds[*row].arg[0]=c.args[2];
        cmds[*row].arg[1]=c.args[3];
        cmds[*row].cost=COST_OF_HELP;
        break;
    }
    updateList();
    if (ui->listWidget->currentRow() != listSize - 1)
    {
    ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
    }
    delete row;
}

void MainWindow::minUstSaid(Command c)
{
    int *row = new int;
    *row = ui->listWidget->currentRow();
    cmds[*row].role = 6;
    cmds[*row].command = c.args[1];
    switch (c.args[1])
    {
    case 0:
        cmds[*row].text = QString::number(*row+1) +": Повышение квалификации министра юстиции";
        cmds[*row].cost= COST_OF_LVLUP;
        break;
    case 1:
        cmds[*row].text = QString::number(*row+1) +": Иск в Международный суд на государство №" + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].cost = COST_OF_COURT;
        break;
    case -2:
        cmds[*row].text = QString::number(*row+1) +": Оказание помощи министром юстиции в делах " + namesOfMins[c.args[2] - 1];
        if (c.args[3] != this->numTeam)
        {
            cmds[*row].text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds[*row].arg[0]=c.args[2];
        cmds[*row].arg[1]=c.args[3];
        cmds[*row].cost=COST_OF_HELP;
        break;
    }

    updateList();
    if (ui->listWidget->currentRow() != listSize - 1)
    {
    ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
    }
    delete row;
}

void MainWindow::MVDSaid(Command c)
{
    int *row = new int;
    *row = ui->listWidget->currentRow();
    cmds[*row].role = 7;
    cmds[*row].command = c.args[1];
    switch (c.args[1])
    {
    case 0:
        cmds[*row].text = QString::number(*row+1) +": Повышение квалификации министра внутренних дел";
        cmds[*row].cost= COST_OF_LVLUP;
        break;
    case 1:
        cmds[*row].text = QString::number(*row+1) +": Усмирение бунтующих в нашем государстве";
        cmds[*row].cost = COST_OF_SUPRESSION;
        break;
    case 2:
        cmds[*row].text = QString::number(*row+1) +": Общая проверка всех министров";
        cmds[*row].cost = COST_OF_CHECK_MIN;
        break;
    case 3:
        cmds[*row].text = QString::number(*row+1) +": Арест " + namesOfMins[c.args[2]-1];
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].cost = COST_OF_AREST;
        break;
    case -2:
        cmds[*row].text = QString::number(*row+1) +": Оказание помощи министром внутренних дел в делах " + namesOfMins[c.args[2] - 1];
        if (c.args[3] != this->numTeam)
        {
            cmds[*row].text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds[*row].arg[0]=c.args[2];
        cmds[*row].arg[1]=c.args[3];
        cmds[*row].cost=COST_OF_HELP;
        break;
    }

    updateList();
    if (ui->listWidget->currentRow() != listSize - 1)
    {
    ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
    }
    delete row;
}

void MainWindow::minComSaid(Command c)
{
    int *row = new int;
    *row = ui->listWidget->currentRow();
    cmds[*row].role = 8;
    cmds[*row].command = c.args[1];
    switch (c.args[1])
    {
    case 0:
        cmds[*row].text = QString::number(*row+1) +": Повышение квалификации министра по связям с общественностью";
        cmds[*row].cost= COST_OF_LVLUP;
        break;
    case 1:
        cmds[*row].text = QString::number(*row+1) +": Заявление в международные СМИ о государстве №" + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].cost = COST_OF_CLAIM;
        break;
    case 2:
        cmds[*row].text = QString::number(*row+1) +": Опровержение лжи в международных СМИ";
        cmds[*row].cost = COST_OF_REFUTATION;
        break;
    case 3:
        cmds[*row].text = QString::number(*row+1) +": Пропаганда в нашем государстве";
        cmds[*row].cost = COST_OF_PROPOGANDA;
        break;
    case 4:
        cmds[*row].text = QString::number(*row+1) +": Разжигание недовольства в государстве №" + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].cost = COST_OF_INC_RIOT;
        break;
    case -2:
        cmds[*row].text = QString::number(*row+1) +": Оказание помощи министром по связям с общественностью в делах " + namesOfMins[c.args[2] - 1];
        if (c.args[3] != this->numTeam)
        {
            cmds[*row].text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds[*row].arg[0]=c.args[2];
        cmds[*row].arg[1]=c.args[3];
        cmds[*row].cost=COST_OF_HELP;
        break;
    }

    updateList();
    if (ui->listWidget->currentRow() != listSize - 1)
    {
    ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
    }
    delete row;
}

void MainWindow::minHelSaid(Command c)
{
    int *row = new int;
    *row = ui->listWidget->currentRow();
    cmds[*row].role = 9;
    cmds[*row].command = c.args[1];
    switch (c.args[1])
    {
    case 0:
        cmds[*row].text = QString::number(*row+1) +": Повышение квалификации министра здравоохранения";
        cmds[*row].cost= COST_OF_LVLUP;
        break;
    case 1:
        cmds[*row].text = QString::number(*row+1) +": Вакцинирование населения от вируса №" + QString::number(c.args[2]);
        cmds[*row].arg[0]  = c.args[2];
        cmds[*row].cost = COST_OF_VACIINE;
        break;
    case 2:
        cmds[*row].text = QString::number(*row+1) +": Заражение вирусом государства №" + QString::number(c.args[2]);
        cmds[*row].arg[0] = c.args[2];
        cmds[*row].cost = COST_OF_INFECT;
        break;
    case -2:
        cmds[*row].text = QString::number(*row+1) +": Оказание помощи министром здравоохранения в делах " + namesOfMins[c.args[2] - 1];
        if (c.args[3] != this->numTeam)
        {
            cmds[*row].text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds[*row].arg[0]=c.args[2];
        cmds[*row].arg[1]=c.args[3];
        cmds[*row].cost=COST_OF_HELP;
        break;
    }

    updateList();
    if (ui->listWidget->currentRow() != listSize - 1)
    {
    ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
    }
    delete row;
}

void MainWindow::zamSaid(Command c) //TODO
{   int *row = new int;
    *row = ui->listWidget->currentRow();
    cmds[*row].role = 10;
    cmds[*row].command = c.args[1];
    switch(c.args[1])
    {
    case -2:
        cmds[*row].text = QString::number(*row+1) +": Оказание помощи заместителем в делах " + namesOfMins[c.args[2] - 1];
        if (c.args[3] != this->numTeam)
        {
            cmds[*row].text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds[*row].arg[0]=c.args[2];
        cmds[*row].arg[1]=c.args[3];
        cmds[*row].cost=COST_OF_HELP;
        break;
    }
    updateList();
    if (ui->listWidget->currentRow() != listSize - 1)
    {
    ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
    }
    delete row;
}



void MainWindow::on_approvePlan_clicked()
{
  QFile of("outdata.txt");
  QTextStream stream(&of);
  of.open(QFile::WriteOnly);
  for (int i = 0; i<listSize; i++)
  {
      stream << cmds[i].role << " " << cmds[i].command << " " << cmds[i].arg[0] << " " << cmds[i].arg[1] << " "
      << cmds[i].arg[2] << " " << cmds[i].arg[3] << " " << cmds[i].arg[4] << "\n";
  }
  of.close();

  repDial->saveList(cmds,listSize);

  updateList();

  if ( transmitter->sendDataToServer() )
  {
  Approved *appr;
  appr = new Approved();
  appr->show();
  }
  this->setDisabled(true);
}

QString MainWindow::beautifyNumber(int num)
{
    QString temp;
    int x;
    temp = QString::number(num);
    x = temp.length()/3;
    if (num>=0)
    {
        if (3*x == temp.length())
        {
            x--;
        }
    }
    else
    {
        if (3*x >=temp.length() - 1)
        {
            x--;
        }
    }

    for (int i = 0; i<x;i++)
    {
        temp.insert(temp.length()-3*(i+1)-i,".");
    }
    return temp;
}

void MainWindow::readData() // REMAKE
{
    this->setEnabled(true);
 //  repDial->clear();
   QString outputCodes;
   QFile in("dataFromServer.txt");
   in.open(QFile::ReadOnly);

   QString temp = in.readAll();
   in.close();
   QTextStream stream(&temp);

   stream >> cash >> numNukes >> numPRO >> happinesOfPopulation >> countOfTeams >> profitMS >> profitTS
          >> profitSH;


   bool **newVerbedMatrix;
   newVerbedMatrix = new bool*[countOfTeams];
   for (int i = 0; i < countOfTeams; i++)
   {
       newVerbedMatrix[i] = new bool[10];

   }

   verbedMatrix = newVerbedMatrix;

   for (int i = 0;i<10;i++)
   {
       stream >> mins[i].lvl;
   }

   if(!stream.atEnd())
   stream.read(1);
   if(!stream.atEnd())
   stream.read(1);

   outputCodes = stream.readLine();
   qDebug() << "OC: " << outputCodes;

   repDial->addCodes(outputCodes);

   List *t = new List;
   int *result = new int;
   while (!stream.atEnd())
   {
       stream >> t->role;
       if (!stream.atEnd())
       {
       stream >> t->command >> t->arg[0]
              >> t->arg[1] >> t->arg[2] >> t->arg[3] >> t->arg[4]
              >> *result;
       repDial->addCommand(t, *result);
       }
   }
   delete t, result;


   ui->cash->setText("ГосРезерв: " + beautifyNumber(cash));
   ui->numNukes->setText("Ядерные ракеты: " + beautifyNumber(numNukes));
   ui->numPRO->setText("Ракеты ПРО: " + beautifyNumber(numPRO));

}

void MainWindow::on_connectionStatusDisp_clicked()
{
    ConnectDial *connectD = new ConnectDial();
    connect(connectD,SIGNAL(sendDataToMainForm(QString,int)),this,SLOT(toStartConnection(QString,int)));
    connectD->show();
}

void MainWindow::toStartConnection(QString host, int port)
{
    numTeam = ui->numOfTeamSpinBox->value();
    nameOfThisTeam = ui->nameEdit->text();
   transmitter->connectToHost(host, port);
}

void MainWindow::onSokConnected()
{    
    ui->connectionStatusDisp->setStyleSheet("background-color:green;");
    this->setDisabled(true);
}

void MainWindow::onSokDisconnected()
{
    ui->connectionStatusDisp->setStyleSheet("background-color:red;");
    ui->nameEdit->setReadOnly(false);
    ui->numOfTeamSpinBox->setReadOnly(false);
}

void MainWindow::readFromServer(int code)
{
    this->setEnabled(true);
    switch (code)
    {
    case 3:
        readData();
        repDial->show();
        repDial->activateWindow();

        clearList();
        updateList();
        break;
    case 4:
            qDebug() << "Матрица вербовки";
        readVerbMatrix();
        break;
    }
}

void MainWindow::on_nameEdit_editingFinished()
{
   if (ui->nameEdit->text()!="") {
       ui->approvePlan->setEnabled(1);
       ui->connectionStatusDisp->setEnabled(true);
       nameOfThisTeam = ui->nameEdit->text();
   } else {
       ui->approvePlan->setDisabled(1);
       ui->connectionStatusDisp->setDisabled(true);
       nameOfThisTeam = "";
   }
}


void MainWindow::on_numOfTeamSpinBox_editingFinished()
{
    numTeam = ui->numOfTeamSpinBox->value();
}

void MainWindow::on_incListSizeButton_clicked()
{

    List *temp = new List[listSize];
    for (int i=0;i<listSize;i++)
    {
        temp[i] = cmds[i];
    }
    delete []cmds;

    listSize++;
    cmds = new List[listSize];

    for (int i=0;i<(listSize-1);i++)
    {
        cmds[i] = temp[i];
    }
    delete []temp;

    cmds[listSize-1].text = QString::number(listSize) + ":";
    updateList();

    if ((!ui->decListSizeButton->isEnabled())&&(listSize>1)) {
        ui->decListSizeButton->setEnabled(true);
    }

}

void MainWindow::on_decListSizeButton_clicked()
{
    if (ui->listWidget->currentRow() == listSize-1) {
        ui->listWidget->setCurrentRow(listSize-2);
    }

    List *temp = new List[listSize-1];
    for (int i=0;i<listSize-1;i++)
    {
        temp[i] = cmds[i];
    }
    delete []cmds;

    listSize--;


    cmds = new List[listSize];

    for (int i=0;i<(listSize);i++)
    {
        cmds[i] = temp[i];
    }
    delete []temp;
    updateList();

    if (listSize == 1)
    {
        ui->decListSizeButton->setDisabled(true);
    }
}

void MainWindow::getNumOfTeams()
{
}

void MainWindow::sendDataToServer()
{
}


int MainWindow::checkForAgents()
{
        qDebug() << "Считаем агентов";
    int result = 0;
    for (int i = 0; i<countOfTeams; i++)
    {
        for (int j = 0 ; j <10; j++)
        {
            if (verbedMatrix[i][j]) { result++ ;}
        }
    }
    return result;
}

void MainWindow::readVerbMatrix()
{

    QFile inf("verbMatrix.txt");
    inf.open(QFile::ReadOnly);
    QTextStream stream(&inf);
    int temp;
    qDebug() << "Начинаем читать матрицу вербовки";

    bool **newVerbedMatrix;
    newVerbedMatrix = new bool*[countOfTeams];
    for (int i = 0; i < countOfTeams; i++)
    {
        newVerbedMatrix[i] = new bool[10];

    }

    verbedMatrix = newVerbedMatrix;

    qDebug() << "Начинаем заполнение";
    for (int i = 0; i < countOfTeams; i++)
    {
        for (int j = 0; j < 10; j++)
        {
                    qDebug() << "Заносим значение" << QString::number(j);
            stream >> temp;
            if (temp) verbedMatrix[i][j] = 1;
            else   verbedMatrix[i][j] = 0;
        }
    }
        qDebug() << "Закончили читать матрицу вербовки";
    inf.close();
}

void MainWindow::loose()
{
    this->setDisabled(true);
}
