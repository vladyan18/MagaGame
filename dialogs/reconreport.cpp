#include "reconreport.h"
#include "ui_reconreport.h"

ReconReport::ReconReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReconReport)
{
    ui->setupUi(this);
    namesOfMins = new QString[10] {"президента", "министра финансов", "министра обороны", "главы КГБ",
                        "министра иностранных дел", "министра юстиции", "министра внутренних дел",
                        "министра по связям с общественностью", "министра здравоохранения", "секретаря"};

}

ReconReport::~ReconReport()
{
    delete ui;
}

void ReconReport::on_pushButton_clicked()
{
    delete this;
}

void ReconReport::addCommand(int mode, int country, Command com)
{
    receivedCommand(com);
    if (mode != currentMode)
    {
        currentMode = mode;
        switch (mode)
        {
        case 1:
            ui->textBrowser->append("<span style=\"color:blue;\">Доклад разведки из страны №" + QString::number(country) + "</span>");
            break;
        }
    }

    if (mode == 2)
    {
      ui->textBrowser->append("<span style=\"color:red;\">Страна №" + QString::number(country) + " попыталась сделать это с нами:</span>");
      ui->textBrowser->append(cmds.text);
    }
    else
    {
     ui->textBrowser->append(cmds.text);
    }
}

void ReconReport::receivedCommand(Command c)
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




void ReconReport::presidentSaid(Command c)
{
    cmds.role = 1;
    cmds.command = c.args[1];


    switch (c.args[1])
    {
    case 0:
        cmds.text = " Повышение квалификации " + namesOfMins[cmds.role-1];
        break;
    case 1:
        cmds.text = " Увольнение " + namesOfMins[c.args[2] - 1];
        cmds.arg[0]=c.args[2];
        cmds.cost=0;
        break;

    case -2:
        cmds.text = " Оказание помощи президентом в делах " + namesOfMins[c.args[2] - 1];

        {
            cmds.text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds.arg[0]=c.args[2];
        cmds.arg[1]=c.args[3];
        break;
    }
}

void ReconReport::minFinSaid(Command c)
{


    cmds.role = 2;
    cmds.command = c.args[1];

    switch(c.args[1]) {
    case 0:
        cmds.text = " Повышение квалификации министра финансов";

        break;
    case 1:
        cmds.text = " Инвестиции в сектора экономики:  ";
       switch (c.args[2])
       {
       case 1:
           cmds.text += "сельское хозяйство, ";
           switch (c.args[3])
           {
           case 2:
               cmds.text += "тяжелая промышленность ";
               break;
           case 3:
               cmds.text += "легкая промышленность ";
               break;
           }

           break;
       case 2:
               cmds.text += "тяжелая промышленность, ";
               switch(c.args[3])
               {
               case 1:
                   cmds.text += "сельское хозяйство" ;
                   break;
               case 3:
                   cmds.text += "легкая промышленность ";
                   break;
               }
           break;
       case 3:
                   cmds.text += "легкая промышленность, ";
                   switch(c.args[3])
                   {
                   case 1:
                       cmds.text += "сельское хозяйство ";
                       break;
                   case 2:
                       cmds.text += "тяжелая промышленность ";
                       break;
                   }

           break;
       }

        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        break;
    case 2:
        cmds.text = " Игра на бирже, ставка: " + QString::number(c.args[3])
                + ", цена: " + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        break;
    case 3:
        cmds.text = " Транш суммы: " + QString::number(c.args[3])
                + " в государство: " + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        break;
    case 4:
        cmds.text = " Передача стране №" + QString::number(c.args[2]) + " производственных мощностей ";
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        cmds.arg[2] = c.args[4];
        switch (c.args[3])
        {
        case 1:
            cmds.text +="сельского хозяйства";
            break;
        case 2:
            cmds.text +="тяжелой промышленности";
            break;
        case 3:
            cmds.text +="легкой промышленности";
            break;
        }
        cmds.text += " в размере " + QString::number(c.args[4]);

        break;
    case -2:
        cmds.text = " Оказание помощи министром финансов в делах " + namesOfMins[c.args[2] - 1];

        {
            cmds.text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds.arg[0]=c.args[2];
        cmds.arg[1]=c.args[3];
        break;
    }


}

void ReconReport::minDefSaid(Command c)
{


    cmds.role = 3;
    cmds.command = c.args[1];
    switch (c.args[1]) {
    case 0:
        cmds.text = " Повышение квалификации министра обороны";
        break;
    case 1:
        cmds.text = " Изменение числа ядерных ракет " + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];

        break;
    case 2:
        cmds.text = " Изменение числа ПРО " + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        break;
    case 3:
        cmds.text = " НАНЕСЕНИЕ ЯДЕРНОГО УДАРА ПО СТРАНЕ №" + QString::number(c.args[2])
                + " число ракет:" + QString::number(c.args[3]);
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        break;
    case 4:
        cmds.text = " Сбить ядерную ракету. Число противоракет:" + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        break;
    case 5:
        cmds.text = " Отмена ядерного удара по стране №" + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        break;
    case 6:
        cmds.text = " Атака сухопутными силами на страну №" + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        break;
    case 7:
        cmds.text = " Набег на страну №" + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        break;
    case 8:
        cmds.text = " Передача ядерных ракет стране №" + QString::number(c.args[2]) + ", в количестве " + QString::number(c.args[3]) + " единиц";
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        break;
    case 9:
        cmds.text = " Передача ракет ПРО стране №" + QString::number(c.args[2]) + ", в количестве " + QString::number(c.args[3]) + " единиц";
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        break;
    case -2:
        cmds.text = " Оказание помощи министром обороны в делах " + namesOfMins[c.args[2] - 1];

        {
            cmds.text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds.arg[0]=c.args[2];
        cmds.arg[1]=c.args[3];
        break;
    }


}

void ReconReport::KGBSaid(Command c)
{


    cmds.role = 4;
    cmds.command = c.args[1];
    switch(c.args[1]) {
    case 0:
        cmds.text = " Повышение квалификации главы КГБ";
        break;
    case 1:
        cmds.text = " Защита " + namesOfMins[c.args[2]-1] + " от иностранного воздействия с силой: "
              + QString::number(c.args[3]) + "%";
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        break;
    case 2:
        cmds.text = " Поиск министра внешней разведки государства №" + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        break;
    case -2:
        cmds.text = " Оказание главой КГБ в делах " + namesOfMins[c.args[2] - 1];

        {
            cmds.text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds.arg[0]=c.args[2];
        cmds.arg[1]=c.args[3];
        break;
    }

}

void ReconReport::midSaid(Command c)
{


    cmds.role = 5;
    cmds.command = c.args[1];

    switch (c.args[1])
    {
    case 0:
        cmds.text = " Повышение квалификации министра иностранных дел";

        break;
    case 1:
        cmds.text = " Диверсия в государстве №" + QString::number(c.args[2]) + " в делах  "
                + namesOfMins[c.args[3]-1];
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];

        break;
    case 2:
        cmds.text = " Вербовка " + namesOfMins[c.args[3]-1] + " в государстве №"
                + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];

        break;
    case 3:
        cmds.text = " Освобождение " + namesOfMins[c.args[3]-1] + " в государстве №"
                + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        cmds.cost = 0;
        break;
    case 4:
        cmds.text = " Приказ министру №" + QString::number(c.args[3]) + " в государстве №"
                + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        cmds.arg[2] = c.args[4];
        cmds.arg[3] = c.args[5];
        cmds.arg[4] = c.args[6];
        cmds.cost = 0;
        break;
    case 5:
        cmds.text = " Убить " + namesOfMins[c.args[3]-1]  + " в государстве №"
                + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        break;
    case 6:
        cmds.text = " Шпионаж за делами " + namesOfMins[c.args[3]-1] + " в государстве №"
                + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        cmds.arg[1] = c.args[3];
        break;
    case -2:
        cmds.text = " Оказание помощи министром иностранных дел в делах " + namesOfMins[c.args[2] - 1];

        {
            cmds.text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds.arg[0]=c.args[2];
        cmds.arg[1]=c.args[3];

        break;
    }



}

void ReconReport::minUstSaid(Command c)
{


    cmds.role = 6;
    cmds.command = c.args[1];
    switch (c.args[1])
    {
    case 0:
        cmds.text = " Повышение квалификации министра юстиции";

        break;
    case 1:
        cmds.text = " Иск в Международный суд на государство №" + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];
        break;
    case -2:
        cmds.text = " Оказание помощи министром юстиции в делах " + namesOfMins[c.args[2] - 1];

        {
            cmds.text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds.arg[0]=c.args[2];
        cmds.arg[1]=c.args[3];

        break;
    }

}

void ReconReport::MVDSaid(Command c)
{


    cmds.role = 7;
    cmds.command = c.args[1];
    switch (c.args[1])
    {
    case 0:
        cmds.text = " Повышение квалификации министра внутренних дел";

        break;
    case 1:
        cmds.text = " Усмирение бунтующих в нашем государстве";

        break;
    case 2:
        cmds.text = " Общая проверка всех министров";

        break;
    case 3:
        cmds.text = " Арест " + namesOfMins[c.args[2]-1];
        cmds.arg[0] = c.args[2];

        break;
    case -2:
        cmds.text = " Оказание помощи министром внутренних дел в делах " + namesOfMins[c.args[2] - 1];

        {
            cmds.text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds.arg[0]=c.args[2];
        cmds.arg[1]=c.args[3];

        break;
    }


}

void ReconReport::minComSaid(Command c)
{


    cmds.role = 8;
    cmds.command = c.args[1];
    switch (c.args[1])
    {
    case 0:
        cmds.text = " Повышение квалификации министра по связям с общественностью";

        break;
    case 1:
        cmds.text = " Заявление в международные СМИ о государстве №" + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];

        break;
    case 2:
        cmds.text = " Опровержение лжи в международных СМИ";

        break;
    case 3:
        cmds.text = " Пропаганда в нашем государстве";

        break;
    case 4:
        cmds.text = " Разжигание недовольства в государстве №" + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];

        break;
    case -2:
        cmds.text = " Оказание помощи министром по связям с общественностью в делах " + namesOfMins[c.args[2] - 1];

        {
            cmds.text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds.arg[0]=c.args[2];
        cmds.arg[1]=c.args[3];

        break;
    }


}

void ReconReport::minHelSaid(Command c)
{


    cmds.role = 9;
    cmds.command = c.args[1];
    switch (c.args[1])
    {
    case 0:
        cmds.text = " Повышение квалификации министра здравоохранения";

        break;
    case 1:
        cmds.text = " Вакцинирование населения от вируса №" + QString::number(c.args[2]);
        cmds.arg[0]  = c.args[2];

        break;
    case 2:
        cmds.text = " Заражение вирусом государства №" + QString::number(c.args[2]);
        cmds.arg[0] = c.args[2];

        break;
    case -2:
        cmds.text = " Оказание помощи министром здравоохранения в делах " + namesOfMins[c.args[2] - 1];

        {
            cmds.text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds.arg[0]=c.args[2];
        cmds.arg[1]=c.args[3];

        break;
    }

}

void ReconReport::zamSaid(Command c) //TODO
{

    cmds.role = 10;
    cmds.command = c.args[1];
    switch(c.args[1])
    {
    case -2:
        cmds.text = " Оказание помощи секретарем в делах " + namesOfMins[c.args[2] - 1];

        {
            cmds.text+= " в государстве №" + QString::number(c.args[3]);
        }
        cmds.arg[0]=c.args[2];
        cmds.arg[1]=c.args[3];

        break;
    }


}
