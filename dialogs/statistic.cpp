#include "statistic.h"
#include "ui_statistic.h"

Statistic::Statistic(MainWindow *prnt, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistic)
{
    ui->setupUi(this);
    ui->govStat->append("Уровень президента: <span style=\" color:green;\">" + QString::number(prnt->mins[0].lvl) + "</span>");
    ui->govStat->append("Уровень  министра финансов: <span style=\" color:green;\">" + QString::number(prnt->mins[1].lvl) + "</span>");
    ui->govStat->append("Уровень  министра обороны: <span style=\" color:green;\">" + QString::number(prnt->mins[2].lvl) + "</span>");
    ui->govStat->append("Уровень  главы КГБ: <span style=\" color:green;\">" + QString::number(prnt->mins[3].lvl) + "</span>");
    ui->govStat->append("Уровень  министра иностранных дел: <span style=\" color:green;\">" + QString::number(prnt->mins[4].lvl) + "</span>");
    ui->govStat->append("Уровень  министра юстиции: <span style=\" color:green;\">" + QString::number(prnt->mins[5].lvl) + "</span>");
    ui->govStat->append("Уровень  министра внутренних дел: <span style=\" color:green;\">" + QString::number(prnt->mins[6].lvl) + "</span>");
    ui->govStat->append("Уровень  министра по связям с общестенностью: <span style=\" color:green;\">" + QString::number(prnt->mins[7].lvl) + "</span>");
    ui->govStat->append("Уровень  министра здравоохранения: <span style=\" color:green;\">" + QString::number(prnt->mins[8].lvl) + "</span>");
    ui->govStat->append("Уровень  заместителя: <span style=\" color:green;\">" + QString::number(prnt->mins[9].lvl) + "</span>");


    ui->ecStat->append("Государственный Резерв: <span style=\" color:green;\">" + prnt->beautifyNumber(prnt->cash) + "</span>");
    ui->ecStat->append("Доход от машиностроения: <span style=\" color:green;\">" + prnt->beautifyNumber(prnt->profitMS) + "</span>");
    ui->ecStat->append("Доход от cельского хозяйства: <span style=\" color:green;\">" + prnt->beautifyNumber(prnt->profitSH) + "</span>");
    ui->ecStat->append("Доход от текстильной промышленности: <span style=\" color:green;\">" + prnt->beautifyNumber(prnt->profitTS) + "</span>");
    ui->ecStat->append("Расход на содержание ядерных ракет: <span style=\" color:red;\">" + prnt->beautifyNumber(prnt->numNukes*50000) + "</span>");
    ui->ecStat->append("Расход на содержание ПРО: <span style=\" color:red;\">" + prnt->beautifyNumber(prnt->numPRO*50000) + "</span>");
    ui->ecStat->append("Расход на содержание иностранных агентов: <span style=\" color:red;\">" + prnt->beautifyNumber(prnt->checkForAgents()*50000) + "</span>");

    ui->milStat->append("<span style=\" color:red;\">Ядерный арсенал: " + QString::number(prnt->numNukes) + "</span>");
    ui->milStat->append("<span style=\" color:blue;\">Арсенал ПРО: " + QString::number(prnt->numPRO) + "</span>");

    ui->otherStat->append("Настроение населения: <span style=\" color:green;\">" + QString::number(prnt->happinesOfPopulation) + "%</span>");
}

Statistic::~Statistic()
{
    delete ui;
}

void Statistic::on_pushButton_clicked()
{
    delete this;
}
