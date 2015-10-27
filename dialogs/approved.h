#ifndef APPROVED_H
#define APPROVED_H

#include <QDialog>

namespace Ui {
class Approved;
}

class Approved : public QDialog
{
    Q_OBJECT

public:
    explicit Approved(QWidget *parent = 0);
    ~Approved();

private slots:
    void on_accept_clicked();

private:
    Ui::Approved *ui;
};

#endif // APPROVED_H
