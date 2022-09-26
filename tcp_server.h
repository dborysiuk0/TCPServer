#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>

class tcp_server : public QObject
{
    Q_OBJECT
public:
   explicit tcp_server(QObject *parent = 0);

signals:

public slots:
    void newConnection();

private:
    QTcpServer *server;

};

#endif // TCP_SERVER_H
