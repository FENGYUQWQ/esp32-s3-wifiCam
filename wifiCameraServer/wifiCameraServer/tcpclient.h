#ifndef TCPCLIENTTHREAD_H
#define TCPCLIENTTHREAD_H

#include "main.h"

#include <QHostAddress>
#include <QList>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>

class tcpClient : public QObject
{
    Q_OBJECT
public:
    explicit tcpClient(QObject *parent = nullptr);

    QTcpServer *tcpServer;/*TCP服务端对象*/

    tcpSocketsInfo *SocketInformation;

    QTcpSocket *tcpServerSocket;

    QList<tcpSocketsInfo*> tcpClientSocketsList;

    void tcpStart(QHostAddress ipAddress,unsigned short port);

    void newTcpConnect();

    void tcpReceiveData();

    void tcpSendData(QByteArray tcpData,QString cameraIP,QString cameraPORT);

    void tcpClientDisconnected();

    unsigned int tcpReceiveDataSize();

    void tcpReceiveDataSizeClear();

    unsigned int tcpConnectCount();

    void isConnectCameraSet();

    void isConnectCameraClr();

    void saveCameraTCPInfo(QString tcpIP,QString tcpPORT);/*保存连接摄像头的IP地址信息和端口信息*/

    void deletCameraTCPInfo(QString tcpIP,QString tcpPORT);/*保存连接摄像头的IP地址信息和端口信息*/

signals:
    void tcpReceiveData_Signal(QByteArray dataArray);

private:
    unsigned int tcpDataSum = 0;

    QHostAddress tcpIP;

    unsigned short tcpPORT = 0;

    bool isConnectCamera = false;/*是否连接相机*/

    bool isCameraConnected = false;/*摄像头是否已经连接*/

    QList<tcpCameraInfo> cameraList;

};

#endif // TCPTHREAD_H