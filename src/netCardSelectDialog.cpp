/*************************************************************************
	> File Name: netCardSelectDialog.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月24日 星期四 16时33分21秒
 ************************************************************************/

#include "netCardSelectDialog.h"

NetCardItem::NetCardItem(QString name, QStringList ipList, QWidget* parent)
    :QWidget(parent)
    ,m_cardName(name)
    ,m_ipList(ipList)
{
    init();
}

NetCardItem::~NetCardItem()
{

}

void NetCardItem::init()
{
    setFixedSize(460, 30);
    m_nameBtn = new QRadioButton(m_cardName, this);
    m_nameBtn->setGeometry(0, 0, 300, 30);
    m_nameBtn->setChecked(false);
    connect(m_nameBtn, SIGNAL(toggled(bool)), this, SIGNAL(cardToggled(bool)));

//    int count = m_ipList.size();
    QString ipListStr = m_ipList.last();
//    QString ipListStr = QString();
//    for(int i=0;i<count;i++)
//    {
//        if(i == 0)
//        {
//            ipListStr = m_ipList[i]; 
//        }
//        else
//        {
//            ipListStr += ("," + m_ipList[i]);
//        }
//    }

    if(ipListStr.isEmpty())
    {
        ipListStr = tr("No IP");
    }

    m_ipLabel = new QLabel(ipListStr, this);
    m_ipLabel->setGeometry(310, 0, 150, 30);
    m_ipLabel->setWordWrap(true);
    m_ipLabel->setAlignment(Qt::AlignLeft | Qt:: AlignVCenter);
}

void NetCardItem::setItemDefault(bool isDefault)
{
    m_nameBtn->setChecked(isDefault);
}

bool NetCardItem::isSelected()
{
    return m_nameBtn->isChecked();
}

QStringList NetCardItem::getIpList()
{
    return m_ipList;
}

NetCardSelectDialog::NetCardSelectDialog(QWidget* parent)
    :QDialog(parent)
{
    init();
    setWindowIcon(QIcon("./resource/logo.png"));
}

NetCardSelectDialog::~NetCardSelectDialog()
{

}

void NetCardSelectDialog::init()
{
    setWindowTitle(tr("Select avaliable NIC"));
    setFixedSize(NET_CARD_SELECT_DIALOG_WIDTH, NET_CARD_SELECT_DIALOG_HEIGHT);

    m_cardCount = 0;

    m_netCardArea = new QScrollArea(this);
    m_netCardArea->setGeometry(10, 30, 480, 130);

    m_netCardWidget = new QWidget();
    m_netCardWidget->setFixedSize(460, m_cardCount*40);
    m_netCardWidget->setContentsMargins(0, 0, 0, 0);

    m_netCardLayout = new QVBoxLayout();

    m_netCardWidget->setLayout(m_netCardLayout);
    m_netCardArea->setWidget(m_netCardWidget);


    m_okButton = new QPushButton(tr("OK"), this);
    m_okButton->setGeometry(140, 170, 110, 30);
    connect(m_okButton, SIGNAL(clicked()), this, SLOT(onOkButtonClicked()));

    m_cancelButton = new QPushButton(tr("Cancel"), this);
    m_cancelButton->setGeometry(270, 170, 110, 30);
    connect(m_cancelButton, SIGNAL(clicked()), this, SLOT(onCancelButtonClicked()));
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
}

void NetCardSelectDialog::setNetworkInfo(QList<NetworkInfo> net_info_list)
{
    int existItemCount = m_cardItemList.size();
    for (int i=0; i<existItemCount; i++)
    {
        m_netCardLayout->removeWidget(m_cardItemList[i]);
    }

    m_cardCount = net_info_list.size();
    m_cardItemList.clear();
    bool firstPhysical = true;
    for(int i=0;i<m_cardCount;i++)
    {
        NetworkInfo info = net_info_list[i];
        QString name = info.readable_name;
        bool isPhysical = info.isPhysical;
        QStringList ipList = info.ipList;

        NetCardItem* item = new NetCardItem(name, ipList);
        if(isPhysical && firstPhysical) // choose first physical card as default selected.
        {
            item->setItemDefault(true);
            firstPhysical = false;
        }
        connect(item, SIGNAL(cardToggled(bool)), this, SLOT(onItemToggled(bool)));
        m_cardItemList.append(item);
        m_netCardLayout->addWidget(item);
    }

    m_netCardWidget->setFixedHeight(m_cardCount*40);
}

QStringList NetCardSelectDialog::getSelectedCardIpList()
{
    int cardItemSize = m_cardItemList.size();
    NetCardItem* item = NULL;
    for(int i=0;i<cardItemSize;i++)
    {
        item = m_cardItemList[i];
        if(item->isSelected())
        {
            break;
        }
    }

    return item->getIpList();
}

void NetCardSelectDialog::onOkButtonClicked()
{
    done(QDialog::Accepted);
}

void NetCardSelectDialog::onCancelButtonClicked()
{
    done(QDialog::Rejected);
}

void NetCardSelectDialog::onItemToggled(bool state)
{
    NetCardItem* item = (NetCardItem*)sender();
    int cardItemSize = m_cardItemList.size();
    NetCardItem* tmp = NULL;
    for(int i=0;i<cardItemSize;i++)
    {
        tmp = m_cardItemList[i];
        disconnect(tmp, SIGNAL(cardToggled(bool)), this, SLOT(onItemToggled(bool)));
        if(item == tmp)
        {
            tmp->setItemDefault(true);
        }
        else
        {
            tmp->setItemDefault(false);
        }
        connect(tmp, SIGNAL(cardToggled(bool)), this, SLOT(onItemToggled(bool)));
    }

    Q_UNUSED(state);
}
