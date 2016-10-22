/*
 * Copyright (c) 2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * This file is part of qMDNS, which is released under the MIT license.
 * For more information, please read the LICENSE file in the root directory
 * of this project.
 */

#include "qMDNS.h"

#include <QHostInfo>
#include <QUdpSocket>
#include <QHostAddress>
#include <QNetworkInterface>

#ifdef Q_OS_LINUX
    #include <sys/socket.h>
#endif

#define READ_BUFFER_SIZE 20
#define HEADER_SIZE 12
#define QDCOUNT_OFFSET 4
#define A_RECORD_SIZE 14
#define NSEC_RECORD_SIZE 20
#define TTL_OFFSET 4
#define IP_OFFSET 10

/*
 * DNS port and mutlicast addresses
 */
const quint16 MDNS_PORT = 5353;
const QHostAddress IPV6_ADDRESS = QHostAddress ("FF02::FB");
const QHostAddress IPV4_ADDRESS = QHostAddress ("224.0.0.251");
const char *MDNS_ADDRESS = "224.0.0.251";

/*
 * mDNS/DNS operation flags
 */
const quint16 kQR_Query       = 0x0000;
const quint16 kQR_Response    = 0x8000;
const quint16 kRecordA        = 0x0001;
const quint16 kRecordPTR      = 0x000c;
const quint16 kRecordAAAA     = 0x001C;
const quint16 kNsecType       = 0x002F;
const quint16 kFQDN_Separator = 0x0000;
const quint16 kFQDN_Length    = 0xC00C;
const quint16 kIN_BitFlush    = 0x8001;
const quint16 kIN_Normal      = 0x0001;

/*
 * DNS query properties
 */
const quint16 kQuery_QDCOUNT = 0x01;
const quint16 kQuery_ANCOUNT = 0x00;
const quint16 kQuery_NSCOUNT = 0x00;
const quint16 kQuery_ARCOUNT = 0x00;

/*
 * DNS response properties
 */
const quint16 kResponse_QDCOUNT = 0x00;
const quint16 kResponse_ANCOUNT = 0x01;
const quint16 kResponse_NSCOUNT = 0x00;
const quint16 kResponse_ARCOUNT = 0x02;

/* Packet constants */
const int MIN_LENGTH = 13;
const int IPI_LENGTH = 10;
const int IP4_LENGTH = IPI_LENGTH + 4;
const int IP6_LENGTH = IPI_LENGTH + 16;

/**
 * Encondes the 16-bit \a number as two 8-bit numbers in a byte array
 */
QByteArray ENCODE_16_BIT (quint16 number) {
    QByteArray data;
    data.append ((number & 0xff00) >> 8);
    data.append ((number & 0xff));
    return data;
}

/**
 * Encodes the 32-bit \a number as four 8-bit numbers
 */
QByteArray ENCODE_32_BIT (quint32 number) {
    QByteArray data;
    data.append ((number & 0xff000000UL) >> 24);
    data.append ((number & 0x00ff0000UL) >> 16);
    data.append ((number & 0x0000ff00UL) >>  8);
    data.append ((number & 0x000000ffUL));
    return data;
}

/**
 * Obtains the 16-bit number stored in the \a upper and \a lower 8-bit numbers
 */
quint16 DECODE_16_BIT (quint8 upper, quint8 lower) {
    return (quint16) ((upper << 8) | lower);
}

/**
 * Binds the given \a socket to the given \a address and \a port.
 * Under GNU/Linux, this function implements a workaround of QTBUG-33419.
 */
bool BIND (QUdpSocket* socket, const QHostAddress& address, const int port) {
    if (!socket)
        return false;


#ifdef Q_OS_LINUX
    int reuse = 1;
    int domain = PF_UNSPEC;

    if (address.protocol() == QAbstractSocket::IPv4Protocol)
        domain = PF_INET;
    else if (address.protocol() == QAbstractSocket::IPv6Protocol)
        domain = PF_INET6;

    socket->setSocketDescriptor (::socket (domain, SOCK_DGRAM, 0),
                                 QUdpSocket::UnconnectedState);

//    setsockopt(socket->socketDescriptor(), IPPROTO_IP, IP_MULTICAST_IF, (char *)&address, sizeof(address));

    setsockopt (socket->socketDescriptor(), SOL_SOCKET, SO_REUSEADDR,
                &reuse, sizeof (reuse));
#endif

//    qWarning() << "address == " << address;
    //return socket->bind (address, port,
    //                     QUdpSocket::ShareAddress |
    //                     QUdpSocket::ReuseAddressHint);
    return socket->bind (port, QUdpSocket::ShareAddress);
}

qMDNS::qMDNS() {
    m_netCardSelectDialog = new NetCardSelectDialog();
    setNetCardInfo();
//    m_disInterfaceProcess = new QProcess(this);

    /* create recv socket */
//    m_recvSocket = new QUdpSocket(this);
//    connect (m_recvSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
//    if (BIND (m_recvSocket, IPV4_ADDRESS, MDNS_PORT))
//    if (BIND (m_recvSocket, QHostAddress::Any, MDNS_PORT))
//    {
//        m_recvSocket->joinMulticastGroup (IPV4_ADDRESS);
//        m_recvSocket->setSocketOption(QAbstractSocket::MulticastLoopbackOption, QVariant(1));
//    }
    
    /* create send socket */
    //m_IPv4SocketList.clear();
    //m_interfaceList.clear();
    //QList<NetworkInfo> list = getNetworkInfoList();
    //int count = list.size();
    //QList<QNetworkInterface> interfacesList = QNetworkInterface::allInterfaces();
    //int count = interfacesList.size();
    //for (int i=0; i<count; i++)
   // {
    //    qWarning() << "--------------" << i << "----------";
    //    qWarning() << "readable_name = " << list[i].readable_name;
    //    qWarning() << "isPhysical = " << list[i].isPhysical;
    //    qWarning() << "ipList = " << list[i].ipList;
    //    qWarning() << "===================================";

        /* Initialize sockets */
    //    QUdpSocket *ipv4Socket = new QUdpSocket(this);
//        m_IPv4Socket = new QUdpSocket (this);
        //m_IPv6Socket = new QUdpSocket (this);

        /* Read and interpret data received from mDNS group */
        //connect (ipv4Socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
//        connect (m_IPv4Socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        //connect (m_IPv6Socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

        /* Bind the sockets to the mDNS multicast group */
        //if (BIND (ipv4Socket, QHostAddress("172.16.2.158"), MDNS_PORT))
        //if (BIND (ipv4Socket, IPV4_ADDRESS, MDNS_PORT))
        //if (BIND (ipv4Socket, QHostAddress(list[i].ipList.last()), MDNS_PORT))
//        if (BIND (m_IPv4Socket, QHostAddress::Any, MDNS_PORT))
//        {
            //qWarning() << "m_interfaceList[i] = " << m_interfaceList[i];
//            m_IPv4Socket->joinMulticastGroup (IPV4_ADDRESS);
            //ipv4Socket->setMulticastInterface(m_interfaceList[i]);
            //ipv4Socket->setSocketOption(QAbstractSocket::MulticastLoopbackOption, 1);
//        }
        //if (BIND (m_IPv6Socket, QHostAddress::AnyIPv6, MDNS_PORT))
        //    m_IPv6Socket->joinMulticastGroup (IPV6_ADDRESS);

        /* Set default TTL to 255 seconds */
        //setTTL(255);

        //m_IPv4SocketList.append(ipv4Socket);
    //}
}

qMDNS::~qMDNS() {
//    int count = m_IPv4SocketList.size();
//    for (int i=0; i<count; i++)
//    {
//        delete m_IPv4SocketList[i];
//    }
//    delete m_IPv6Socket;
    delete m_IPv4Socket;
}

/**
 * Returns the only running instance of this class
 */
qMDNS* qMDNS::getInstance() {
    static qMDNS instance;
    return &instance;
}

/**
 * Ensures that the given \a string is a valid mDNS/DNS address.
 */
QString qMDNS::getAddress (const QString& string) {
    QString address = string;

    if (!string.endsWith (".local") && !string.contains ("."))
        address = string + ".local";

    if (string.endsWith ("."))
        return "";

    return address;
}

void qMDNS::setNetCardInfo()
{
    QString ipAddress = QString();
    QList<NetworkInfo> networkInfoList;
    QStringList realCardIpList;
    QStringList virtualCardIpList;
    QStringList ipList;
    networkInfoList.clear();
    m_networkInfoList.clear();
    realCardIpList.clear();
    virtualCardIpList.clear();
    ipList.clear();
    QString interfaceName = QString();
    QString readableInterfaceName = QString();
    QList<QNetworkInterface> interfacesList = QNetworkInterface::allInterfaces();
    int interfaceCount = interfacesList.size();
    if (interfaceCount == 0) 
    {
        //return networkInfoList;
    }

    for(int i=0;i<interfaceCount;i++)
    {
        NetworkInfo info;
        QNetworkInterface singleInterface = interfacesList[i];
        interfaceName = singleInterface.name();
        readableInterfaceName = singleInterface.humanReadableName();
        bool isRealCard = isRealNetCard(interfaceName);

        info.readable_name = readableInterfaceName;
        info.isPhysical = isRealCard;
        bool isLoopBack = false;

        if(isRealCard)
        {
            QList<QNetworkAddressEntry> addressList = singleInterface.addressEntries();
            for(int j=0;j<addressList.size();j++)
            {
                QNetworkAddressEntry entry = addressList[j];
                QHostAddress address = entry.ip();
                if(address != QHostAddress::LocalHost && address.toIPv4Address())
                {
                    realCardIpList.append(address.toString());
                }
                else if(address == QHostAddress::LocalHost)
                {
                    isLoopBack = true;
                }
            }

            info.ipList = realCardIpList;
            if(!isLoopBack)
            {
                networkInfoList.prepend(info);
                m_networkInfoList.prepend(info);
                m_interfaceList.prepend(singleInterface);
            }
        }
        else
        {
            QList<QNetworkAddressEntry> addressList = singleInterface.addressEntries();
            for(int j=0;j<addressList.size();j++)
            {
                QNetworkAddressEntry entry = addressList[j];
                QHostAddress address = entry.ip();
                if(address != QHostAddress::LocalHost && address.toIPv4Address())
                {
                    virtualCardIpList.append(address.toString());
                }
                else if(address == QHostAddress::LocalHost)
                {
                    isLoopBack = true;
                }
            }

            info.ipList = virtualCardIpList;
            if(!isLoopBack)
            {
                networkInfoList.append(info);
                m_networkInfoList.append(info);
                m_interfaceList.append(singleInterface);
            }
        }
    }

    m_netCardSelectDialog->setNetworkInfo(networkInfoList);
}

/**
 *get network card ip list
 */
//QList<NetworkInfo> qMDNS::getNetworkInfoList()
//QNetworkInterface qMDNS::getNetworkInfoList()
int qMDNS::getNetworkInfoList()
{
    //return networkInfoList;

    int result = m_netCardSelectDialog->exec();

    if(result == QDialog::Rejected)
    {
        qDebug() << "User abort select network card.";
        return -1;
    }

    QStringList ipList = m_netCardSelectDialog->getSelectedCardIpList();
    
    if (ipList.size() == 0)
    {
        //QMessageBox::critical(this, tr("Httpd Server")
         //       ,tr("Unable to start the server: Not avaliable physical NIC!"));
        //return false;
    }
    else
    {
        int count = m_interfaceList.size();
        for (int i=0; i<count; i++)
        {
            if (m_networkInfoList[i].ipList == ipList)
            {
                qWarning() << "get interfacelist " << i;
                //return m_interfaceList[i];
                return i;
            }
        }
    }

//    m_listenedAddress = ipList;
//    ipAddress = ipList[0];// choose first ip as default.

    qWarning() << "last get interfacelist 0";
    //return m_interfaceList[0];
    return 0; 
//    return ipAddress;

}

bool qMDNS::isRealNetCard(QString cardName)
{
#ifdef Q_OS_WIN32
    for(int i=0;i<NET_CARD_MAX_CNT;i++)
    {
        QString cardFolderNameRightPart = QString::number(i);
        QString cardFolderName = QString();
        int cardFolderNameRightPartLen = cardFolderNameRightPart.length();
        if(cardFolderNameRightPartLen == 1)
        {
            cardFolderName = "000" + cardFolderNameRightPart;
        }
        else if(cardFolderNameRightPartLen == 2)
        {
            cardFolderName = "00" + cardFolderNameRightPart;
        }

        QString nativePath = QDir::toNativeSeparators(NET_CARD_REGEDIT_WHOLE_KEY) + cardFolderName;
        QSettings* reg = new QSettings(nativePath, QSettings::NativeFormat);
        QString regNetCfgInstanceIdStr = reg->value("NetCfgInstanceId").toString();
        QString regMatchingDeviceIdStr = reg->value("MatchingDeviceId").toString();
        if(cardName == regNetCfgInstanceIdStr && regMatchingDeviceIdStr.startsWith("pci", Qt::CaseInsensitive))
        {
            return true;
        }
    }

    return false;
#endif

#ifdef Q_OS_UNIX
    Q_UNUSED(cardName);
    return true;
#endif
}

/**
 * Changes the TTL send to other computers in the mDNS network
 */
void qMDNS::setTTL (const quint32 ttl) {
    m_ttl = ttl;
    m_IPv4Socket->setSocketOption(QAbstractSocket::MulticastTtlOption, m_ttl);
//    int count = m_IPv4SocketList.size();
//    for (int i=0; i<count; i++)
//    {
//        m_IPv4SocketList[i]->setSocketOption(QAbstractSocket::MulticastTtlOption, m_ttl);
//    }
}

/**
 * Performs a mDNS lookup to find the given host \a name.
 * If \a preferIPv6 is set to \c true, then this function will generate a
 * packet that requests an AAAA-type Resource Record instead of an A-type
 * Resource Record.
 */
void qMDNS::lookup () {
//    QByteArray data;

//    /* Get the host name and domain */
//    QString host = "_gwn_controller";
//    QString udp = "_udp";
//    QString domain = "local";

//    /* Check that domain length is valid */
//    if (host.length() > 255) {
//        qWarning() << Q_FUNC_INFO << host << "is too long!";         /*
//        return;                                                       * mDNS/DNS operation flags
//    }                                                                 */
//

    char host[] = "_gwn_controller";                                   
    char udp[] = "_udp";                                              
    char domain[] = "local";                                          
    int curPos = 0;

    if (NULL != sendBuf)
    {
        free(sendBuf);
    }
    sendBuf = (uint8_t*)malloc(MAX_BUF);
    if (NULL == sendBuf)
    {
        qWarning() << "malloc sendBuf error";
        return;
    }

    size_t n = strlen(host);
    if (n > 255) {
        qWarning() << Q_FUNC_INFO << host << "is too long!"; 
        return;
    }

    uint8_t header[] = { 
        0x00, 0x00,   // ID
        0x00, 0x00,   // kQR_Query
        0x00, 0x01,   // kQuery_QDCOUNT
        0x00, 0x00,   // kQuery_ANCOUNT
        0x00, 0x00,   // kQuery_NSCOUNT
        0x00, 0x00    // kQuery_ARCOUNT
    };
    memcpy(sendBuf+curPos, header, HEADER_SIZE);
    curPos += HEADER_SIZE;

//    /* Create header & flags */                                      
//    data.append (ENCODE_16_BIT (0));                                 
//    data.append (ENCODE_16_BIT (kQR_Query));                         
//    data.append (ENCODE_16_BIT (kQuery_QDCOUNT));                    
//    data.append (ENCODE_16_BIT (kQuery_ANCOUNT));                    
//    data.append (ENCODE_16_BIT (kQuery_NSCOUNT));                    
//    data.append (ENCODE_16_BIT (kQuery_ARCOUNT));                    
                                                                     
    /* Add name data */                                              
//    data.append (host.length());                                     
    size_t hostLen = strlen(host);
    sendBuf[curPos] = (uint8_t)hostLen;
    curPos += 1;
//    data.append (host.toUtf8());                                     
    for (int i = 0; i < hostLen; i++) {
        sendBuf[curPos+i] = tolower(host[i]);
    }
    curPos += hostLen;
                                                                     
    /* Add udp data*/                                                
//    data.append (udp.length());                                      
    size_t udpLen = strlen(udp);
    sendBuf[curPos] = (uint8_t)udpLen;
    curPos += 1;
//    data.append (udp.toUtf8());                                      
    for (int i = 0; i < udpLen; i++) {
        sendBuf[curPos+i] = tolower(udp[i]);
    }                                                                
    curPos += udpLen;

    /* Add domain data */                                            
//    data.append (domain.length());                                   
    size_t domainLen = strlen(domain);
    sendBuf[curPos] = (uint8_t)domainLen;
    curPos += 1;
//    data.append (domain.toUtf8());                                   
    for (int i = 0; i < domainLen; i++) {
        sendBuf[curPos+i] = tolower(domain[i]);
    }                                                               
    curPos += domainLen;

    /* Add FQDN/TLD separator */                                     
//    data.append ((char) kFQDN_Separator);     //0x0000                       
    uint8_t separator[] = {0x00}; 
    memcpy(sendBuf+curPos, separator, 1);
    curPos += 1;
                                                                     
    /* Add IPv4 record type */                                       
//    data.append (ENCODE_16_BIT (kRecordPTR));   //0x000c                     
//    data.append (ENCODE_16_BIT (kIN_Normal));   //0x0001                     
    uint8_t ipv4Record[] = {
        0x00, 0x0c,      //kRecordPTR
        0x00, 0x01       //kIN_Normal
    };
    memcpy(sendBuf+curPos, ipv4Record, 4);
    curPos += 4;
                                                                     
    qWarning() << "sendbuf = " << sendBuf;                           
    sendto(mMdnsSocket, sendBuf, curPos, 0, (struct sockaddr*)&m_serverAddr, sizeof(struct sockaddr));

    memset(recvBuf, 0, sizeof(recvBuf));
    socklen_t server_len = sizeof(struct sockaddr);
    //recvfrom(mMdnsSocket, recvBuf, sizeof(recvBuf), 0, (struct sockaddr*)&m_serverAddr, &server_len);
    int number = recvfrom(mMdnsSocket, recvBuf, sizeof(recvBuf), 0, NULL, 0);
    if (number < 0)
    {
        qWarning() << "recvfrom error";
    }
    qWarning() << "recvBuf = " << recvBuf;
    qWarning() << "recvBuf number = " << number;
    parseRecv(recvBuf, number);
}


void qMDNS::parseRecv(uint8_t data[], int number)
{
    QHostAddress hostAddress("172.16.2.133");

    qWarning() << "data = " << data;

    /* Packet is a valid mDNS datagram */
//    if (data.length() > MIN_LENGTH) {
    if (number > MIN_LENGTH) {
        /* Get the lengths of the host name and domain */
        int n = 12;
        int hostLength = data[n];
        int domainLength = data[n + hostLength + 1];

        /* Read the host name until we stumble with the domain length character */
        char name[hostLength];
        memset(name, 0, hostLength);
        int h = n + 1;
        for (int i = 0; i < hostLength; i++) {
            name[i] = tolower(data[h+i]);
        } 
        qWarning() << "name = " << name;
//        while (h <= data.length() && data.at (h) != (char) domainLength) {
//            name.append (data.at (h));
//            ++h;
//        }

        /* Read domain length until we stumble with the FQDN/TLD separator */
        char domain[domainLength];
        memset(domain, 0, domainLength);
        int d = n + hostLength + 2;
        for (int i = 0; i < domainLength; i++) {
            domain[i] = tolower(data[d+i]);
        }
        qWarning() << "domain = " << domain;
//        while (d <= data.length() && data.at (d) != kFQDN_Separator) {
//            domain.append (data.at (d));
//            ++d;
//        }

        /* Construct the full host name (name + domain) */
        QString host = getAddress ((QString)name + "." + (QString)domain);
        qWarning() << "host ====================== " << host;
        logFile(QString("host = ").append(host));

        if (host.contains("GWN", Qt::CaseInsensitive)) {
            /*parse mdns gwn info when lookup*/
            saveDeviceInfo(data, hostAddress, 91);
            /*parse mdns gwn info when restart network*/
            saveDeviceInfo(data, hostAddress, 148);
        }
    //}
    }
}

/**
 * Called when we receive data from a mDNS client on the network.
 */
void qMDNS::onReadyRead() {
    QByteArray data;
    QUdpSocket* socket = qobject_cast<QUdpSocket*> (sender());
    QHostAddress hostAddress;
    quint16 port;

    /* Read data from the socket */
    if (socket) {
        while (socket->hasPendingDatagrams()) {
            data.resize (socket->pendingDatagramSize());
            socket->readDatagram (data.data(), data.size(), &hostAddress, &port);
        }
    }
    qWarning() << "hostAddress = " << hostAddress << ", port = " << port;
    logFile(QString("hostAddress = ").append(hostAddress.toString()).append(QString(", port = ")).append(port));

    /* Packet is a valid mDNS datagram */
    if (data.length() > MIN_LENGTH) {
        /* Get the lengths of the host name and domain */
        int n = 12;
        int hostLength = data.at (n);
        int domainLength = data.at (n + hostLength + 1);

        /* Read the host name until we stumble with the domain length character */
        QString name;
        int h = n + 1;
        while (h <= data.length() && data.at (h) != (char) domainLength) {
            name.append (data.at (h));
            ++h;
        }

        /* Read domain length until we stumble with the FQDN/TLD separator */
        QString domain;
        int d = n + hostLength + 2;
        while (d <= data.length() && data.at (d) != kFQDN_Separator) {
            domain.append (data.at (d));
            ++d;
        }

        /* Construct the full host name (name + domain) */
        QString host = getAddress (name + "." + domain);
        qWarning() << "host ====================== " << host;
        logFile(QString("host = ").append(host));

        if (host.contains("GWN", Qt::CaseInsensitive)) {
            /*parse mdns gwn info when lookup*/
            //saveDeviceInfo(data, hostAddress, 91);
            /*parse mdns gwn info when restart network*/
            //saveDeviceInfo(data, hostAddress, 148);
        }
    }
}

//void qMDNS::saveDeviceInfo(QByteArray data, QHostAddress hostAddress, int t)
void qMDNS::saveDeviceInfo(uint8_t data[], QHostAddress hostAddress, int t)
{
//    QString role;
//    QString product;
//    QString mac;
//    QString version;
    int roleLength = data[t];
    int productLength = data[t + roleLength + 1];
    int macLength = data[t + roleLength + productLength + 2];
    int versionLength = data[t + roleLength + productLength + macLength + 3];
    char endChar = (char)data[t + roleLength + productLength + macLength + versionLength + 4];
    
    char role[roleLength];
    char product[productLength];
    char mac[macLength];
    char version[versionLength];
    memset(role, 0, roleLength);
    memset(product, 0, productLength);
    memset(mac, 0, macLength);
    memset(version, 0, versionLength);

    t += 6;
    for (int i = 0; i < roleLength-5; i++) {
        role[i] = tolower(data[t]);
        t++;
    }
//    while (t <= data.length() && data.at(t) != (char)productLength) {
//        role.append(data.at(t));
//        ++t;
//    }
    qWarning() << "role =======================" << role;
    logFile(QString("role = ").append((QString)role));

    t += 9;
    for (int i = 0; i < productLength-8; i++) {
        product[i] = tolower(data[t]);
        t++;
    }
    //    while (t <= data.length() && data.at(t) != (char)macLength) {
    //        product.append(data.at(t));
    //        ++t;
    //    }
    qWarning() << "product ====================" << product;
    logFile(QString("product = ").append((QString)product));

    t += 5;
    for (int i = 0; i < macLength-4; i++) {
        mac[i] = tolower(data[t]);
        t++;
    }
    //    while (t <= data.length() && data.at(t) != versionLength) {
    //        mac.append(data.at(t));
    //        ++t;
    //    }
    qWarning() << "mac ========================" << mac;
    logFile(QString("mac = ").append((QString)mac));

    t += 9;
    for (int i = 0; i < versionLength-8; i++) {
        version[i] = tolower(data[t]);
        t++;
    }
//    while (t <= data.length() && data.at(t) != endChar) {
//        version.append(data.at(t));
//        ++t;
//    }
    qWarning() << "version ========================" << version;
    logFile(QString("version = ").append((QString)version));

//    if (t > data.length()) {
//        return;
//    }

    QString qProduct = QString(product);
    QString qRole = QString(role);
    QString qMac = QString(mac);
    QString qVersion = QString(version);

    if (qProduct.contains("GWN", Qt::CaseInsensitive) && 7==qProduct.size() && 17==qMac.size()) {
        DEVICE_INFO deviceInfo;
        deviceInfo.macAddr = qMac;
        deviceInfo.IPv4Addr = hostAddress;
        deviceInfo.deviceName = qProduct;
        deviceInfo.version = qVersion;
        if (QString("master") == qRole) {
            deviceInfo.isMaster = true;
        } else {
            deviceInfo.isMaster = false;
        }

        emit refreshSignal(deviceInfo);
    }
}

/**
 * Sends the given \a data to both the IPv4 and IPv6 mDNS multicast groups
 */
void qMDNS::sendPacket (QByteArray& data) {
    if (!data.isEmpty()) {
        //int count = m_IPv4SocketList.size();
//        qWarning() << "sendPacket";
//        logFile(QString("sendPacket"));
//        memset(sendBuf, 0, sizeof(sendBuf));
//        strcpy(sendBuf, data.data());
        //strcpy(sendBuf, "sendpacket");
//        qWarning() << "sendbuf = " << sendBuf;

//        memset(&m_serverAddr, 0, sizeof(m_serverAddr));
//        m_serverAddr.sin_family = AF_INET;
//        m_serverAddr.sin_port = htons(MDNS_PORT);
//        m_serverAddr.sin_addr.s_addr = inet_addr(MDNS_ADDRESS);

//        sendto(mMdnsSocket, sendBuf, strlen(sendBuf), 0, (struct sockaddr*)&m_serverAddr, sizeof(struct sockaddr));
//        m_IPv4Socket->writeDatagram (data, IPV4_ADDRESS, MDNS_PORT);
        //for (int i=0; i<count; i++)
        //{
        //    qWarning() << "sendPacket index = " << i;
        //    m_IPv4SocketList[i]->writeDatagram (data, IPV4_ADDRESS, MDNS_PORT);
        //}
        //m_IPv6Socket->writeDatagram (data, IPV6_ADDRESS, MDNS_PORT);
    }
}

/**
 *
 * write log to logfile
 */
void qMDNS::logFile(QString text)
{
    QFile file("log.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

    QTextStream out(&file);
    out << text << "\n";
    file.close();
}


int qMDNS::selectNetCard()
{
    //QNetworkInterface iface = getNetworkInfoList();
    int index = getNetworkInfoList();
    if (index >= 0) 
    {
        // Create the UDP socket
        mMdnsSocket = -1;
        int ret = 0;

        mMdnsSocket = socket(AF_INET, SOCK_DGRAM, 0);
        if (mMdnsSocket < 0) {
            return -1;
        }
        qWarning() << "init mMdnsSocket ok ++++++++++++++++++++++++";

        int reuse = 1;
        if(setsockopt(mMdnsSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(reuse)) < 0)
        {
            qWarning() << "Setting SO_REUSEADDR error";
            close(mMdnsSocket);
            return -1;
        }
        qWarning() << "reus ok +++++++++++++++++++++++++++++";

        // set a socket option
//        bool bBroadcast = true;
//        if (setsockopt(mMdnsSocket, SOL_SOCKET, SO_BROADCAST, (char*)&bBroadcast, sizeof(bool)) < 0)
//        {
//            qWarning() << "setsockopt broadcast error!";
//            close(mMdnsSocket);
//            return -1;
//        }

        int loopBack=1;
        if(setsockopt(mMdnsSocket, IPPROTO_IP, IP_MULTICAST_LOOP, (char*)&loopBack, sizeof(loopBack)) < 0)
        {
            qWarning() << "setsockopt ip_multicast_loop error!!!";
            close(mMdnsSocket);
            return -1;
        }
        qWarning() << "loopback ok ++++++++++++++++++++++++";

        memset(&m_serverAddr, 0, sizeof(m_serverAddr));
        m_serverAddr.sin_family = AF_INET;
        m_serverAddr.sin_port = htons(MDNS_PORT);
        //m_serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        m_serverAddr.sin_addr.s_addr = inet_addr(MDNS_ADDRESS);

        //if (bind(mMdnsSocket, (sockaddr*) &address, sizeof(address)) < 0) {
        if (bind(mMdnsSocket, (struct sockaddr*) &m_serverAddr, sizeof(struct sockaddr)) < 0) {
            qWarning() << "bind failed";
            return -1;
        }
        qWarning() << "bind ok ++++++++++++++++++++++++";


        struct in_addr addr = {0};
        addr.s_addr=inet_addr(m_networkInfoList[index].ipList.last().toStdString().c_str());
        qWarning() << "addr.s_addr source = " << m_networkInfoList[index].ipList.last().toStdString().c_str();
        struct ip_mreq ipmr;
        ipmr.imr_interface.s_addr = addr.s_addr;
        ipmr.imr_multiaddr.s_addr = inet_addr(MDNS_ADDRESS);
        ret=setsockopt(mMdnsSocket,IPPROTO_IP,IP_ADD_MEMBERSHIP,(const char*)&ipmr,sizeof(ipmr));
        qWarning() << "add membership ok ++++++++++++++++++++++";

        if(-1 == setsockopt(mMdnsSocket, IPPROTO_IP, IP_MULTICAST_IF, (char *)&addr, sizeof(addr)))
        {
            qWarning() << "set error IP_MULTICAST_IF";
            close(mMdnsSocket);
            mMdnsSocket = -1;
        }
        qWarning() << "multicast_if ok ++++++++++++++++++++++";

#if 0
        struct timeval tv;
        tv.tv_sec = 2;
        tv.tv_usec = 0;
        ret = setsockopt(mMdnsSocket,SOL_SOCKET,SO_RCVTIMEO,(char*)&tv,sizeof(tv));
        if(-1 == ret)
        {
            qWarning() << "setsockopt recvtimeout error!!!";
            close(mMdnsSocket);
            return -1;
        }
        qWarning() << "selectNetCard ok ++++++++++++++++++++=";
#endif



        //memset(sendBuf, 0, sizeof(sendBuf));
        //strcpy(sendBuf, "test string");
        //qWarning() << "sendbuf = " << sendBuf;

        //sendto(mMdnsSocket, sendBuf, strlen(sendBuf), 0, (struct sockaddr*)&m_serverAddr, sizeof(struct sockaddr));



//        mMdnsSocket = socket;

#if 0
        int count = m_interfaceList.size();
        Loading::instance()->start();
        for (int i=0; i<count; i++)
        {
            QString interfaceName = m_interfaceList[i].humanReadableName();
            QString cmd = QString();
            if (i == index)
            {
                cmd = QString("netsh interface set interface \"").append(interfaceName).append(QString("\" enabled"));
                qWarning() << "cmd = " << cmd;
                logFile(cmd);
            }
            else
            {
                cmd = QString("netsh interface set interface \"").append(interfaceName).append(QString("\" disabled"));
                qWarning() << "cmd = " << cmd;
                logFile(cmd);
            }
            m_disInterfaceProcess->start(cmd);
            m_disInterfaceProcess->waitForStarted();
            m_disInterfaceProcess->waitForFinished();
        }
        Loading::instance()->stop();

        m_IPv4Socket->leaveMulticastGroup(IPV4_ADDRESS);
        delete m_IPv4Socket;
        QUdpSocket *bindSocket = new QUdpSocket(this);

        //qWarning() << "select address == " << address;
        /* Read and interpret data received from mDNS group */
        connect (bindSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        //connect (m_IPv6Socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

        /* Bind the sockets to the mDNS multicast group */
        //if (BIND (bindSocket, QHostAddress::Any, MDNS_PORT))
        //if (BIND (ipv4Socket, QHostAddress("172.16.2.158"), MDNS_PORT))
        //if (BIND (ipv4Socket, IPV4_ADDRESS, MDNS_PORT))
        //if (BIND (m_IPv4Socket, QHostAddress(list[i].ipList.last()), MDNS_PORT))
        qWarning() << "bind address = " << m_networkInfoList[index].ipList.last();
        if (BIND (bindSocket, QHostAddress(m_networkInfoList[index].ipList.last()), MDNS_PORT))
        {
            qWarning() << "iface = " << m_interfaceList[index];
            bindSocket->setMulticastInterface(m_interfaceList[index]);
            bindSocket->joinMulticastGroup (IPV4_ADDRESS, m_interfaceList[index]);
            //bindSocket->joinMulticastGroup (IPV4_ADDRESS);
            bindSocket->setSocketOption(QAbstractSocket::MulticastLoopbackOption, QVariant(1));
        }
        //if (BIND (m_IPv6Socket, QHostAddress::AnyIPv6, MDNS_PORT))
        //    m_IPv6Socket->joinMulticastGroup (IPV6_ADDRESS);

        /* Set default TTL to 255 seconds */
//        setTTL(255);
        m_IPv4Socket = bindSocket;
#endif
    }
}

QList<QNetworkInterface> qMDNS::getInterfaceList()
{
    return m_interfaceList;
}
