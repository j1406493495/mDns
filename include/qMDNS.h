/*
 * Copyright (c) 2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * This file is part of qMDNS, which is released under the MIT license.
 * For more information, please read the LICENSE file in the root directory
 * of this project.
 */

#include "Common.h"
#include "netCardSelectDialog.h"
#include "Loading.h"

#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#define MAX_BUF 1024
#define NET_CARD_MAX_CNT 12
#define NET_CARD_REGEDIT_WHOLE_KEY "HKEY_LOCAL_MACHINE/SYSTEM/CurrentControlSet/Control/Class/{4D36E972-E325-11CE-BFC1-08002BE10318}/"

class QHostInfo;
class QUdpSocket;
class QHostAddress;

//typedef struct __NetworkInfo
//{
//    QString readable_name;
//    bool isPhysical;
//    QStringList ipList;
//}NetworkInfo;

/**
 * \brief Implements a simple mDNS responder using Qt
 *
 * This implementation is able perform mDNS queries and mDNS responses in any
 * operating system supported by the Qt network module.
 *
 * You can obtain the IP of an mDNS device using the \c lookup() function,
 * the \c hostFound() signal will be emitted whenever this class interprets
 * a mDNS response packet and obtains valid information about a remote host.
 *
 * You can change the name that the local computer uses to identify itself
 * in the mDNS network using the \c setHostName() function.
 *
 * \todo Implement NSEC block code generation in the \c sendResponse() packet
 */
class qMDNS : public QObject {
    Q_OBJECT

  signals:
    void refreshSignal(DEVICE_INFO);

  public:
    static qMDNS* getInstance();
    QString getAddress (const QString& string);
    //QList<NetworkInfo> getNetworkInfoList();
    int getNetworkInfoList();
    //QNetworkInterface getNetworkInfoList();
    bool isRealNetCard(QString);
    void logFile(QString);
    void setNetCardInfo();
    QList<QNetworkInterface> getInterfaceList();
    void parseRecv(uint8_t[], int, QHostAddress);

  protected:
    explicit qMDNS();
    ~qMDNS();

  public slots:
    void setTTL (const quint32 ttl);
    void lookup ();
    int selectNetCard();

  private slots:
    void onReadyRead();
    void sendPacket (QByteArray& data);
    void saveDeviceInfo(uint8_t[], QHostAddress, int);
    //void saveDeviceInfo(QByteArray, QHostAddress, int);

  private:
    uint8_t *sendBuf;
    uint8_t recvBuf[MAX_BUF];
    //char recvBuf[MAX_BUF];
    sockaddr_in m_serverAddr;
    int mMdnsSocket;
    quint32 m_ttl;
    QList<QUdpSocket*> m_IPv4SocketList;
    QList<QNetworkInterface> m_interfaceList;
    QList<NetworkInfo> m_networkInfoList;
    QUdpSocket *m_recvSocket;
    NetCardSelectDialog* m_netCardSelectDialog;
    QUdpSocket *m_IPv4Socket;
    QProcess *m_disInterfaceProcess;
//    QUdpSocket* m_IPv6Socket;



    static uint8_t _queryHeader[];
    uint8_t* _expected;
    int _expectedLen;
    // Current parsing state
    int _index;
    // Response data
    uint8_t* _response;
    int _responseLen;

};
