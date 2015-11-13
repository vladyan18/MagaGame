#include "nettransmitter.h"
#include <QFile>
#include <dialogs/report.h>

class Report;
NetTransmitter::NetTransmitter(MainWindow *_parent)
{
    _sok = new QTcpSocket();
    parentForm = _parent;
    connect(this,SIGNAL(dataReceived(int)),parentForm,SLOT(readFromServer(int)));

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
    /*
     *
     QByteArray t;
     QTextStream stream(&t);
     stream << QString::number(numTeam) + nameOfThisTeam;
     */
    QByteArray ar= QString(QString::number(parentForm->numTeam) + parentForm->nameOfThisTeam).toUtf8();
   _sok->write(ar.data());
}

void NetTransmitter::onSokDisconnected()
{

}

void NetTransmitter::onSokReadyRead()
{
    QFile of,mf("verbMatrix.txt");
    QTextStream stream(&of);
    QTextStream stream1(&mf);
    QString temp;
    int mode;
    QByteArray doc;
    temp = _sok->read(1);
    qDebug() << temp;
    mode = QString(temp).toInt();

QString temp2;
QTextStream str1(&doc);
    switch (mode)
    {
    case 3:
        qDebug() << "Принимаем данные от сервера";
        of.setFileName("dataFromServer.txt");
        doc = _sok->readAll();
        of.open(QFile::WriteOnly);
        while (!str1.atEnd())
        {
        temp2 = str1.readLine();
        if (temp2[0] != 'M')
            {
                stream << temp2 << endl;
            }
        else
            {
                mf.open(QFile::WriteOnly);
                stream1 << str1.readAll();
                mf.close();
                break;
            }
        }
        of.close();
        emit dataReceived(3);
        emit dataReceived(4);
    break;
    case 4:
        qDebug() << "Принимаем матрицу от сервера";
        of.setFileName("verbMatrix.txt");
        doc = _sok->readAll();
        of.open(QFile::WriteOnly);
        stream << doc;
        of.close();
        emit dataReceived(4);
        break;
    }
}
