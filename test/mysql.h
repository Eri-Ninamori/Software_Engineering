#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>
#include <QSqlDatabase>

struct GuestInfo {
    quint32 id;
    QString name;
    quint8 age;
    QString sex;
    QString phone;
    quint32 guestid;
    QString scheduling;
    QString server;
};

struct UserInfo {
    QString username;
    QString password;
    QString authority;
};

class mysql : public QObject
{
    Q_OBJECT
public:
    explicit mysql(QObject *parent = nullptr);

    void init();

    // 查询所有嘉宾
    quint32 getGuestCnt();

    // 查询某页的全部嘉宾数据,页数从 0 开始
    QList<GuestInfo> getPageGuest(quint32 page, quint32 per_page);

    // 增添嘉宾
    bool addGuest(GuestInfo info);

    // 删除嘉宾
    bool delGuest(quint32 id);

    // 清空所有嘉宾
    void clearGuestTable();

    // 修改嘉宾信息
    bool updateGuest(GuestInfo info);

    // 查询所有用户
    QList<UserInfo> getAllUser();

    // 查询当前用户是否存在
    bool isExit(QString username);

    // 修改用户信息
    bool updateUser(UserInfo info);

    // 添加用户
    bool addUser(UserInfo info);

    // 删除用户
    bool delUser(QString username);

signals:

private:
    QSqlDatabase my_db;
};

#endif // MYSQL_H
