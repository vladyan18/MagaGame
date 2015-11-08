#include "report.h"
#include "ui_report.h"


Report::Report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
}

Report::~Report()
{
    delete ui;
}

void Report::on_approveButton_clicked()
{
    this->hide();
}

void Report::addCommand(List *com, int result)
{

       // if (savedList[i].role == com->role && savedList[i].command == com->command
        //        && savedList[i].arg == com->arg) {
            if (result)
            {
                ui->textBrowser->append(savedList[numOfCom].text
                                        + "<span style=\"color:green\"> Выполнено</span>");

            }
            else
            {
                ui->textBrowser->append(savedList[numOfCom].text
                                        + "<span style=\"color:red\"> Не выполнено</span>");

            }
            numOfCom++;
      //  }

}

void Report::saveList(List cmds[], int listSize)
{
    clearAll();
    savedList = new List[listSize];
    savedListSize = listSize;
    for (int i = 0; i<listSize; i++)
    {
        savedList[i] = cmds[i];
    }

}

void Report::addCodes(QString codes)
{
    int command;
    QTextStream stream(&codes);
    while(!stream.atEnd())
    {
        stream >> command;
        switch(command)
        {
        case 100:
            ui->textBrowser->append("В нашей стране совершена диверсия!");
            break;
        case 300:
            ui->textBrowser->append("<span style=\"color:red; font-size:30pt\">НА НАШЕЙ ТЕРРИТОРИИ ПРОИЗОШЕЛ ЯДЕРНЫЙ ВЗРЫВ!</span>");
            ui->textBrowser->append("<span style=\"color:red; font-size:18pt\">Огромные потери среди населения! Повреждены важные объекты промышленности и инфраструктуры.</span>");
            break;
        case 310:
            break;
        case 320:
            break;
        }

        if (command > 3100 && command < 3200)
        {
        ui->textBrowser->append("<span style=\"color:red\">Из страны №"+QString::number(command - 3100) + " по нам выпущена ядерная ракета!</span>");
        }
    }
}

void Report:: clearAll()
{
    if (numOfCom)
    {
        delete []savedList;
    }
    ui->textBrowser->clear();
    numOfCom = 0;
    savedListSize = -1;
}
