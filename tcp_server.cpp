#include "tcp_server.h"

tcp_server::tcp_server(QObject *parent): QObject(parent)
{
    server = new QTcpServer(this);

    // whenever a user connects, it will emit signal
    connect(server, SIGNAL(newConnection()),
                this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 9999)){
            qDebug() << "Server could not start";
    }
        else{
            qDebug() << "Server started!";
    }
}

void tcp_server::newConnection(){
    //need to grab the socket
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("hello, i'm server");
    socket->flush();

    socket->waitForBytesWritten(3000);
    socket->close();
}
