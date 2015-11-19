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
    QFile of;
    QTextStream stream(&of);
    QString temp;
    int mode;
    QByteArray doc;
    temp = _sok->read(1);
    qDebug() << temp;
    mode = QString(temp).toInt();

QString temp2;
QTextStream str1(&doc);
        qDebug() << "Принимаем данные от сервера";
        of.setFileName("dataFromServer.txt");
        doc = _sok->readAll();
        int res[3] = {1,0,0};
        int mode1 = 0;
        of.open(QFile::WriteOnly);

        while (!str1.atEnd())
        {
        temp2 = str1.readLine();
        switch (mode1)
        {
        case 0:
            if (temp2[0] != 'M' && temp2[0] != 'P')
                {

                    stream << temp2 << endl;
                }
            else
                if (temp2[0] == 'M')
                {
                    mode1 = 1;
                    res[1] = 1;
                    of.close();
                    of.setFileName("verbMatrix.txt");
                    of.open(QFile::WriteOnly);
                }
                else
                {
                    mode1 = 2;
                    res[2] = 1;
                    of.close();
                    of.setFileName("reconData.txt");
                    of.open(QFile::WriteOnly);
                }
            break;
        case 1:
           if (temp2[0] != 'P')
           stream << temp2 << endl;
           else
           {
               mode1 = 2;
               res[2] = 1;
               of.close();
               of.setFileName("reconData.txt");
               of.open(QFile::WriteOnly);
           }
            break;
        case 2:
                stream << temp2 << endl;
            break;
        }
    }
        of.close();

        if (res[0])emit dataReceived(3);
        if (res[1])emit dataReceived(4);
        if (res[2])emit dataReceived(5);
}
