#include "pickthemin.h"
#include "ui_pickthemin.h"

PickTheMin::PickTheMin(int com,int except,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PickTheMin)
{
    command = com;
    withoutMin = except;
    ui->setupUi(this);

    QString names[10] = {"Президент", "Министр финансов", "Министр обороны", "Глава КГБ",
                        "Министр иностранных дел", "Министр юстиции", "Министр внутренних дел",
                        "Министр по связям с общественностью", "Министр здравоохранения", "Заместитель"};

    for (int i = 1; i<=10; i++)
        {
        if (i==withoutMin)
            {
            continue;
            }
        else
            {
            ui->comboBox->addItem(names[i-1]);
            }
        }

}

PickTheMin::~PickTheMin()
{
    delete ui;
}

void PickTheMin::on_buttonBox_accepted()
{
    int *choice = new int;
    *choice = ui->comboBox->currentIndex() + 1;
    if ((withoutMin!=0)&&(*choice >= withoutMin))
    {
        (*choice)++;
    }
    emit sendDataToParent(command,*choice);
    delete this;
}

void PickTheMin::on_buttonBox_rejected()
{
    delete this;
}
