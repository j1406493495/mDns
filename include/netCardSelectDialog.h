/*************************************************************************
	> File Name: netCardSelectDialog.h
	> Author: 
	> Mail: 
	> Created Time: 2015年09月24日 星期四 16时28分14秒
 ************************************************************************/

#ifndef _NETCARDSELECTDIALOG_H
#define _NETCARDSELECTDIALOG_H

#include <QDialog>
#include <QList>
#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>

#define NET_CARD_SELECT_DIALOG_WIDTH 500
#define NET_CARD_SELECT_DIALOG_HEIGHT 210

typedef struct __NetworkInfo
{
    QString readable_name;
    bool isPhysical;
    QStringList ipList;
}NetworkInfo;

class NetCardItem : public QWidget
{
    Q_OBJECT
public:
    NetCardItem(QString name, QStringList ipList, QWidget* parent = NULL);
    ~NetCardItem();

    void setItemDefault(bool isDefault);
    bool isSelected();
    QStringList getIpList();
private:
    void init();

    QString m_cardName;
    QStringList m_ipList;

    QRadioButton* m_nameBtn;
    QLabel* m_ipLabel;

signals:
    void cardToggled(bool);
};

class NetCardSelectDialog : public QDialog
{
    Q_OBJECT
public:
    NetCardSelectDialog(QWidget* parent = NULL);
    ~NetCardSelectDialog();

    void setNetworkInfo(QList<NetworkInfo> net_info_list);
    QStringList getSelectedCardIpList();
private:
    void init();

    int m_cardCount;
    QScrollArea* m_netCardArea;
    QWidget* m_netCardWidget;
    QVBoxLayout* m_netCardLayout;
    QPushButton* m_okButton;
    QPushButton* m_cancelButton;

    QList<NetCardItem*> m_cardItemList;
public slots:
    void onOkButtonClicked();
    void onCancelButtonClicked();
    void onItemToggled(bool);
};

#endif
