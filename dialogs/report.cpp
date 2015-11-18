#include "report.h"
#include "ui_report.h"
#include <QScrollBar>




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
    int command, arg1, arg2, arg3;
    QTextStream stream(&codes);
    while(!stream.atEnd())
    {
        stream >> command;
        switch(command)
        {
        case 100:
            ui->textBrowser->append("В нашей стране совершена диверсия!");
            ui->textBrowser->append("<img source=\"sabotage2.jpg\"/>");
            break;
        case 101:
            ui->textBrowser->append("Один из наших министров прервал все связи с зарубежной разведкой.");
            break;
        case 110:
            stream >> arg1;
            ui->textBrowser->append("Был убит министр №" + QString::number(arg1) + "!" );
            break;
        case 200:
            ui->textBrowser->append("Наше государство было подло оклеветано в СМИ!");
            ui->textBrowser->append("<img source=\"pravda.jpg\"/>");
            break;
        case 201:
            ui->textBrowser->append("Выдвинув опровержение, одно из государств выставило нас дураками в СМИ!");
            ui->textBrowser->append("<img source=\"pravda.jpg\"/>");
            break;
        case 202:
            ui->textBrowser->append("<span style=\"font-size:20pt; font-weight:600; color:#ee3901;\">В нашей стране восстание! Работа всех секторов экономики нарушена, мы несем огромные убытки!</span> <img source=\"riot.jpg\"/>");
            break;
        case 203:
            ui->textBrowser->append("<span style=\"color:green; font-size:15pt\">Удар сил порядка остановил восстание в нашей стране!</span>");
            break;
        case 204:
            ui->textBrowser->append("<span style=\"color:#ee3901; font-size:20pt\">Расстрелы мирных граждан вызвали недовольство!</span>");
            break;
        case 205:
            stream >> arg1 >> arg2;
            ui->textBrowser->append("<span style=\"color:green; font-size:12pt\">Нам поступил транш суммой " + beautifyNumber(arg1) + " от государства №" + QString::number(arg2) + ".</span>");
            break;
        case 206:
            stream >> arg1;
            ui->textBrowser->append("В ходе торгов на бирже прибыль составила:  " + beautifyNumber(arg1));
            break;
        case 207:
            stream >> arg1;
            ui->textBrowser->append("<span style=\"color:blue; font-size:15pt\">Обнаружена активность агентов государства №" + QString::number(arg1) + " в нашем правительстве!</span>");
            break;
        case 208:
            ui->textBrowser->append("<span style=\"color:black; font-size:15pt\">В стране резко выросло количество больных! Нужно принять меры!</span>");
            break;
            break;
        case 209:
            ui->textBrowser->append("<span style=\"color:black; font-size:15pt\">Разработанная вакцина оказалась неэффективна!</span>");
            break;
        case 210:
            stream >> arg1;
            stream >> arg2;
            ui->textBrowser->append("<span style=\"color:green; font-size:12pt\">Государство №"+ QString::number(arg1) +" передало нам ядерные ракеты в количестве " + QString::number(arg2) +" единиц</span>");
            break;
        case 211:
            stream >> arg1;
            stream >> arg2;
            ui->textBrowser->append("<span style=\"color:green; font-size:12pt\">Государство №"+ QString::number(arg1) +" передало нам ракеты ПРО в количестве " + QString::number(arg2) +" единиц</span>");
            break;
        case 212:
            stream >> arg1 >> arg2 >> arg3;
            switch(arg2)
            {
            case 1:
                ui->textBrowser->append("<span style=\"color:green; font-size:12pt\">Государство №"+ QString::number(arg1) +" оказало нам помощь в сельском хоязйстве в размере" + beautifyNumber(arg3) + "</span>");
                break;
            case 2:
                ui->textBrowser->append("<span style=\"color:green; font-size:12pt\">Государство №"+ QString::number(arg1) +" оказало нам помощь в тяжелой промышленности в размере" + beautifyNumber(arg3)+ "</span>");
                break;
            case 3:
                ui->textBrowser->append("<span style=\"color:green; font-size:12pt\">Государство №"+ QString::number(arg1) +" оказало нам помощь в легкой промышленности в размере" + beautifyNumber(arg3)+ "</span>");
                break;
            }
            break;
        case 214:
            ui->textBrowser->append("<span style=\"color:blue; font-size:15pt\">В нашем правительстве обнаружены шпионы!</span>");

            break;
        case 215:
            ui->textBrowser->append("<span style=\"color:green; font-size:30pt\">Новое правительство готово к работе!</span>");
            break;
        case 216:
            ui->textBrowser->append("<span style=\"color:green; font-size:12pt\">КГБ сообщает, что все чисто, вроде бы...</span>");
            break;


        case 300:
            ui->textBrowser->append("<span style=\"color:red;font-weight:600; font-size:30pt\">НА НАШЕЙ ТЕРРИТОРИИ ПРОИЗОШЕЛ ЯДЕРНЫЙ ВЗРЫВ!</span>");
            ui->textBrowser->append("<img source=\"nuke1.jpg\"/>");
            ui->textBrowser->append("<span style=\"color:red; font-weight:600; font-size:16pt\">Огромные потери среди населения! Повреждены важные объекты промышленности и инфраструктуры.</span>");
            break;
        case 310:
            break;
        case 320:
            break;
        case 500:
            stream >> arg1;
            ui->textBrowser->append("<span style=\"color:red; font-weight:600; font-size:30pt\">Наша страна захвачена!</span>");
            ui->textBrowser->append("<span style=\"color:red; font-weight:600; font-size:13pt\">Войска государства №" + QString::number(arg1) + " уже входят в здание правительства!</span>");
            emit loose();
            break;
        case 3000:
            stream >> arg1;
            ui->textBrowser->append("<span style=\"color:red; font-weight:600; font-size:13pt\">Обнаружен пуск ядерной ракеты в стране №" + QString::number(arg1) + "!</span>");
            break;
        case 3001:
            stream >> arg1;
            ui->textBrowser->append("<span style=\"color:green; font-weight:600; font-size:13pt\">Наша система ПРО сбила " + QString::number(arg1) + " ракет!</span>");
            break;
        }
    }

    QScrollBar *t = ui->textBrowser->verticalScrollBar();
    t->setSliderPosition(0);
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

void Report:: clear()
{
    ui->textBrowser->clear();
}


QString Report::beautifyNumber(int num)
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
        if (3*x >= temp.length() - 1)
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
