#ifndef GETNUMDIALOG_H
#define GETNUMDIALOG_H
#include <ministrys/mindef.h>
#include <ministrys/minfin.h>
#include <ministrys/iminister.h>
#include <QDialog>


class MinDef;
class MinFin;
class IMinister;

namespace Ui {

class GetNumDialog;
}



class GetNumDialog : public QDialog
{
    Q_OBJECT

public:

    explicit GetNumDialog(IMinister *prnt, int mode, int nextDialMode, int min, int max, QWidget *parent = 0);
    ~GetNumDialog();

private slots:
    void on_pushButton_clicked();

    void on_GetNumDialog_destroyed();

    void on_GetNumDialog_finished(int result);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::GetNumDialog *ui;

    IMinister  *prnt;
    int mode;
    int nextDialMode;
};

#endif // GETNUMDIALOG_H
