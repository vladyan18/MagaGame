#include "helpdialog.h"
#include "ui_helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
    names = new QString[10]{"Президент", "Министр финансов", "Министр обороны", "Глава КГБ",
                        "Министр иностранных дел", "Министр юстиции", "Министр внутренних дел",
                        "Министр по связям с общественностью", "Министр здравоохранения", "Секретарь"};

    for (int i = 0; i<10; i++)
        {
            {
            ui->comboBox->addItem(names[i]);
            }
        }
}

HelpDialog::~HelpDialog()
{
    delete ui;
}

void HelpDialog::on_approveButton_clicked()
{
    helper = ui->comboBox->currentIndex() + 1;
    receiver = ui->comboBox_2->currentIndex() + 1;
    if (receiver>=withoutMin)
    {
        receiver++;
    }
    sendDataToParent(helper, receiver);
    delete this;
}

void HelpDialog::on_comboBox_currentIndexChanged(int index)
{
    withoutMin = index+1;
    ui->comboBox_2->clear();
    for (int i = 1; i<=10; i++)
        {
        if (i==withoutMin)
            {
            continue;
            }
        else
            {
            ui->comboBox_2->addItem(names[i-1]);
            }
        }
}
