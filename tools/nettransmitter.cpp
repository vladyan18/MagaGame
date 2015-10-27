#include "nettransmitter.h"
#include <QFile>
#include <dialogs/report.h>

class Report;
NetTransmitter::NetTransmitter(MainWindow *_parent)
{
    _sok = new QTcpSocket();
    parentForm = _parent;
    connect(this,SIGNAL(dataReceived()),parentForm,SLOT(readFromServer()));

    connect(_sok, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
    connect(_sok, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(_sok, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));

    connect(_sok, SIGNAL(connected()), parentForm, SLOT(onSokConnected()));
    connect(_sok, SIGNAL(disconnected()), parentForm, SLOT(onSokDisconnected()));    
}

void NetTransmitter::connectToHost(QString host, int port)
{

    _sok->connectToHost(host, port);
}

bool NetTransmitter::sendDataToServer()
{
    if ( _sok->isWritable() )
    {
        QByteArray *doc = new QByteArray;
        QFile *dataFile = new QFile;

        dataFile->setFileName("outdata.txt");
        dataFile->open(QFile::ReadOnly);
        *doc = dataFile->readAll();
        dataFile->close();

        _sok->write(*doc);

        delete doc;
        delete dataFile;
        return true;
    }
    else
    {
        return false;
    }
}

void NetTransmitter::onSokConnected()
{
    QByteArray ar= QString(QString::number(parentForm->numTeam) + parentForm->nameOfThisTeam).toUtf8();
   _sok->write(ar.data());
}

void NetTransmitter::onSokDisconnected()
{

}

void NetTransmitter::onSokReadyRead()
{
    QString temp;
    int mode;
    QByteArray doc;
    temp = _sok->read(1);
    mode = QString(temp).toInt();
    doc = _sok->readAll();
    QFile of("dataFromServer.txt");
    QTextStream stream(&of);
    of.open(QFile::WriteOnly);
    stream << doc;
    of.close();
    emit dataReceived();
}
