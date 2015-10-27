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
