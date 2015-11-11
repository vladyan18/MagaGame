#ifndef NETTRANSMITTER_H
#define NETTRANSMITTER_H

#include <QObject>
#include <QTcpSocket>
#include "mainwindow.h"

class NetTransmitter : public QObject
{
    Q_OBJECT
public:
    NetTransmitter(MainWindow*);
    void connectToHost(QString, int);
    bool sendDataToServer();
signals:
    void dataReceived(int code);
private:
    QTcpSocket* _sok;
    MainWindow* parentForm;
private slots:
    void onSokConnected();
    void onSokDisconnected();
    void onSokReadyRead();
};

#endif // NETTRANSMITTER_H
