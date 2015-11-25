#include "pickthemin.h"
#include "ui_pickthemin.h"
#include <QList>
#include <QDebug>


PickTheMin::PickTheMin(IMinister *prnt,int com, int except, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PickTheMin)
{
    this->prnt = prnt;
    command = com;
    withoutMin = except;
    ui->setupUi(this);
    ui->buttonBox->setDisabled(true);

    QString names[10] = {"Президент", "Министр финансов", "Министр обороны", "Глава КГБ",
                        "Министр иностранных дел", "Министр юстиции", "Министр внутренних дел",
                        "Министр по связям с общественностью", "Министр здравоохранения", "Секретарь"};

    for (int i = 1; i<=10; i++)
        {
        if (i==withoutMin)
            {
            continue;
            }
        else
            {
            ui->comboBox->addItem(names[i-1]);
            ministers.push_back(i);
            }
        }
    if (ministers.empty()) {
    ui->comboBox->setDisabled(true);
    ui->buttonBox->setDisabled(true);

    }
}

PickTheMin::PickTheMin(IMinister *prnt, int com, int country, bool **verbMatrix, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PickTheMin)
{
    verbedMatrix = verbMatrix;
    this->prnt = prnt;
    command = com;
    ui->setupUi(this);
    mode = -1;
    this->country = country;

    QString names[10] = {"Президент", "Министр финансов", "Министр обороны", "Глава КГБ",
                        "Министр иностранных дел", "Министр юстиции", "Министр внутренних дел",
                        "Министр по связям с общественностью", "Министр здравоохранения", "Секретарь"};

    for (int i = 1; i<=10; i++)
        {
        if (verbMatrix[country-1][i-1])
            {
            ui->comboBox->addItem(names[i-1]);
            ministers.push_back(i);
            }
        }

}

PickTheMin::PickTheMin(IMinister *prnt, int com, int country, int mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PickTheMin)
{
    this->prnt = prnt;
    this->mode = mode;
    command = com;
    ui->setupUi(this);

    if (mode == 1)
    {
    ui->label->setText("Выберите две отрасли:");
    ui->buttonBox->setDisabled(true);
    }
    else
    {
    ui->label->setText("Выберите отрасль:");
    ui->buttonBox->setDisabled(true);
    }

    this->setWindowTitle("Выбор отраслей");

    QString names[3] = {"Сельское хозяйство", "Тяжелая промышленность", "Легкая промышленность"};
    for (int i = 1; i<=3; i++)
        {

            ui->comboBox->addItem(names[i-1]);
            ministers.push_back(i);
        }
}

PickTheMin::~PickTheMin()
{
    delete ui;
}

void PickTheMin::on_buttonBox_accepted()
{


    if (mode == 1)
    {
        prnt->c.args[1] = command;
        prnt->c.args[2] = ministers[choice];
        prnt->c.args[3] = ministers[choice2];
    delete this;
    } else
    {
        choice = ui->comboBox->currentIndex();
        prnt->c.args[1] = command;
        prnt->c.args[2] = ministers[choice];
        delete this;
    }

}

void PickTheMin::on_buttonBox_rejected()
{
    delete this;
}

void PickTheMin::on_comboBox_activated(int index)
{
    if (step == 2)
    {
        choice2 = index;
        if (choice2 >= choice) choice2++;
        ui->buttonBox->setEnabled(true);
        ui->comboBox->setDisabled(true);

        QString names[3] = {"Сельское хозяйство", "Тяжелая промышленность", "Легкая промышленность"};
        int temp = index;
        if (temp>=choice && step == 2)
        ui->listWidget->addItem(names[index+1]);
        else
        ui->listWidget->addItem(names[index]);
    }

    if (step == 1)
    {
        choice = index;
        if (mode == 1 )
        {
            QString names[3] = {"Сельское хозяйство", "Тяжелая промышленность", "Легкая промышленность"};
            ui->listWidget->addItem(names[index]);

            step++;
            ui->comboBox->clear();

            for (int i = 0; i<3; i++)
                {
                if (i == choice) continue;
                    ui->comboBox->addItem(names[i]);
                }

        }
        else
        {
            ui->comboBox->setDisabled(true);
            ui->buttonBox->setEnabled(true);
        }
    }

    if (mode == 2)
    {
        QString names[3] = {"Сельское хозяйство", "Тяжелая промышленность", "Легкая промышленность"};
        ui->listWidget->addItem(names[index]);
    }
    else if (mode == 0)
    {
    QString names[10] = {"Президент", "Министр финансов", "Министр обороны", "Глава КГБ",
                            "Министр иностранных дел", "Министр юстиции", "Министр внутренних дел",
                            "Министр по связям с общественностью", "Министр здравоохранения", "Секретарь"};
        if (index >= withoutMin - 1 && withoutMin != 0)
        ui->listWidget->addItem(names[index+1]);
        else
        ui->listWidget->addItem(names[index]);
    }
    else if (mode == -1)
    {
        QString names[10] = {"Президент", "Министр финансов", "Министр обороны", "Глава КГБ",
                                "Министр иностранных дел", "Министр юстиции", "Министр внутренних дел",
                                "Министр по связям с общественностью", "Министр здравоохранения", "Секретарь"};
        vector<QString> verbedNames;
        for (int i = 1; i<=10; i++)
            {
            if (verbedMatrix[country-1][i-1])
                {
                verbedNames.push_back(names[i-1]);
                }
            }
         ui->listWidget->addItem(verbedNames[index]);
    }

    if (mode == 1 && ui->listWidget->count() == 2) {ui->buttonBox->setEnabled(true);}


}
