#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(QWidget *parent = 0);
    ~HelpDialog();

private slots:
    void on_approveButton_clicked();
    void on_comboBox_currentIndexChanged(int index);

signals:
    void sendDataToParent(int, int);

private:
    Ui::HelpDialog *ui;
    int helper;
    int receiver;
    int withoutMin;
    QString *names;
};

#endif // HELPDIALOG_H
