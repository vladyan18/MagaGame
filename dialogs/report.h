#ifndef REPORT_H
#define REPORT_H

#include <QDialog>
#include <mainwindow.h>
#include <QString>

class List;

namespace Ui {
class Report;
}

class Report : public QDialog
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = 0);
    void addCommand(List*, int);
    void saveList(List[], int);
    void clearAll();
    void clear();
    void addCodes(QString);
    ~Report();

private slots:
    void on_approveButton_clicked();

private:
    Ui::Report *ui;
    List *savedList;
    int savedListSize;
    int numOfCom = 0;
    QString beautifyNumber(int num);
};

#endif // REPORT_H
