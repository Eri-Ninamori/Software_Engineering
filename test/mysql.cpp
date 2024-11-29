#include "mysql.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
#include <QCoreApplication>

mysql::mysql(QObject *parent)
    : QObject{parent}
{
    init();
    GuestInfo g;
    // g.name = "李天成";
    // g.age = 18;
    // g.sex = "男";
    // g.phone = "13912345678";
    // g.guestid = 123456789;
    // g.scheduling = "玄武湖公园";
    // g.server = "李佳宁";
    // addGuest(g);

    // g.name = "张书华";
    // g.age = 22;
    // g.sex = "女";
    // g.phone = "15898765432";
    // g.guestid = 987654321;
    // g.scheduling = "中山陵";
    // g.server = "王宇航";
    // addGuest(g);

    // g.name = "王子涵";
    // g.age = 27;
    // g.sex = "男";
    // g.phone = "18654329876";
    // g.guestid = 456789123;
    // g.scheduling = "新街口";
    // g.server = "张语嫣";
    // addGuest(g);

    // g.name = "刘雅静";
    // g.age = 30;
    // g.sex = "女";
    // g.phone = "13265478901";
    // g.guestid = 741852963;
    // g.scheduling = "鼓楼广场";
    // g.server = "陈浩轩";
    // addGuest(g);

    // g.name = "陈锦辉";
    // g.age = 35;
    // g.sex = "女";
    // g.phone = "15012348765";
    // g.guestid = 369258147;
    // g.scheduling = "秦淮河畔";
    // g.server = "周静怡";
    // addGuest(g);

    // g.name = "林志远";
    // g.age = 40;
    // g.sex = "男";
    // g.phone = "13876543210";
    // g.guestid = 258147369;
    // g.scheduling = "栖霞山";
    // g.server = "刘晨曦";
    // addGuest(g);

    // g.name = "周梦瑶";
    // g.age = 45;
    // g.sex = "女";
    // g.phone = "15678901234";
    // g.guestid = 192837465;
    // g.scheduling = "浦口桥北";
    // g.server = "黄子睿";
    // addGuest(g);

    // g.name = "黄俊杰";
    // g.age = 50;
    // g.sex = "男";
    // g.phone = "17765432109";
    // g.guestid = 678123945;
    // g.scheduling = "雨花台烈士陵园";
    // g.server = "赵梦婷";
    // addGuest(g);

    // g.name = "赵雪琳";
    // g.age = 55;
    // g.sex = "男";
    // g.phone = "18987654321";
    // g.guestid = 834759216;
    // g.scheduling = "江宁大学城";
    // g.server = "杨子骞";
    // addGuest(g);

    // g.name = "郑浩然";
    // g.age = 60;
    // g.sex = "女";
    // g.phone = "13701234567";
    // g.guestid = 543216789;
    // g.scheduling = "夫子庙";
    // g.server = "林梓豪";
    // addGuest(g);

    // qDebug() << getGuestCnt();
    // getPageGuest(0, 3);
    // qDebug() << delGuest(66);
    // clearGuestTable();
    // g.id = 70;
    // g.age = 57;
    // qDebug() << updateGuest(g);

    // UserInfo u;
    // u.username = "Alice";
    // u.password = "X7q$eL92";
    // u.authority = "administer";
    // qDebug() << addUser(u);

    // u.username = "Alex";
    // u.password = "P@9wL3rT";
    // u.authority = "user";
    // qDebug() << addUser(u);

    // u.username = "Jack";
    // u.password = "J8k%Z1yQ";
    // u.authority = "user";
    // qDebug() << addUser(u);
    // qDebug() << addUser(u);

    // u.username = "Emma";
    // u.password = "T4m#G9nX";
    // u.authority = "user";
    // qDebug() << addUser(u);

    // u.username = "Bob";
    // u.password = "L2a!V7pR";
    // u.authority = "administer";
    // qDebug() << addUser(u);

    // u.username = "Lucy";
    // u.password = "Y6d&X3qZ";
    // u.authority = "user";
    // qDebug() << addUser(u);

    // qDebug() << isExit("Bob");
    // qDebug() << isExit("bob");
    // getAllUser();
    // u.password = "$X9mL@5qR7!Zp8#T";
    // qDebug() << updateUser(u);
    // qDebug() << delUser("Lucy");
}

void mysql::init()
{
    if (QSqlDatabase::drivers().isEmpty()) {
        QMessageBox::information(nullptr, tr("No database drivers found"),
                                 tr("This demo requires at least one Qt database driver. "
                                    "Please check the documentation how to build the "
                                    "Qt SQL plugins."));
    }

    my_db = QSqlDatabase::addDatabase("QSQLITE");

    // auto str = QCoreApplication::applicationDirPath() + "\\database.db";
    // qDebug() << str;
    // my_db.setDatabaseName(str);

    my_db.setDatabaseName("C:\\Users\\Eri-Ninamori\\Documents\\test\\database.db");
    if (!my_db.open()) {
        QMessageBox::warning(nullptr, tr("Unable to open database"),
                             tr("An error occurred while "
                                "opening the connection: %1") .arg(my_db.lastError().text()));
        return;
    };
}

quint32 mysql::getGuestCnt()
{
    QSqlQuery q(my_db);
    q.exec("SELECT COUNT (id) FROM Guest;");

    quint32 count = 0;
    while (q.next()) {
        count = q.value(0).toUInt();
    }
    return count;
}

QList<GuestInfo> mysql::getPageGuest(quint32 page, quint32 per_page)
{
    QSqlQuery q(my_db);
    QString strSql = QString("SELECT * FROM Guest ORDER BY id LIMIT %1 offset %2;").
                     arg(per_page).
                     arg(page * per_page);
    q.exec(strSql);

    QList<GuestInfo> list;
    GuestInfo info;
    while (q.next()) {
        info.id = q.value(0).toUInt();
        info.name = q.value(1).toString();
        info.age = q.value(2).toUInt();
        info.sex = q.value(3).toString();
        info.phone = q.value(4).toString();
        info.guestid = q.value(5).toUInt();
        info.scheduling = q.value(6).toString();
        info.server = q.value(7).toString();
        list.push_back(info);
    }
    return list;
}

bool mysql::addGuest(GuestInfo info)
{
    QSqlQuery q(my_db);
    QString strSql = QString("INSERT INTO Guest VALUES (null, '%1', %2, '%3', '%4', %5, '%6', '%7');").
                     arg(info.name).
                     arg(info.age).
                     arg(info.sex).
                     arg(info.phone).
                     arg(info.guestid).
                     arg(info.scheduling).
                     arg(info.server);
    return q.exec(strSql);
}

bool mysql::delGuest(quint32 id)
{
    QSqlQuery q(my_db);
    QString strSql = QString("DELETE FROM Guest WHERE id = %1;").
                     arg(id);
    return q.exec(strSql);
}

void mysql::clearGuestTable()
{
    QSqlQuery q(my_db);
    QString strSql = QString("DELETE FROM Guest;");
    q.exec(strSql);
}

bool mysql::updateGuest(GuestInfo info)
{
    QSqlQuery q(my_db);
    QString strSql = QString("UPDATE Guest SET name = '%1', age = %2, sex = '%3', phone = '%4', guestid = %5, scheduling = '%6', server = '%7' WHERE id=%8;").
                     arg(info.name).
                     arg(info.age).
                     arg(info.sex).
                     arg(info.phone).
                     arg(info.guestid).
                     arg(info.scheduling).
                     arg(info.server).
                     arg(info.id);
    return q.exec(strSql);
}

QList<UserInfo> mysql::getAllUser()
{
    QSqlQuery q(my_db);
    QString strSql = QString("SELECT * FROM Username;");
    q.exec(strSql);

    QList<UserInfo> list;
    UserInfo info;
    while (q.next()) {
        info.username = q.value(0).toString();
        info.password = q.value(1).toString();
        info.authority = q.value(2).toString();
        list.push_back(info);
    }
    return list;
}

bool mysql::isExit(QString username)
{
    QSqlQuery q(my_db);
    QString strSql = QString("SELECT * FROM Username WHERE username = '%1';").
                     arg(username);
    q.exec(strSql);
    return q.next();
}

bool mysql::updateUser(UserInfo info)
{
    QSqlQuery q(my_db);
    QString strSql = QString("UPDATE Username SET password = '%2', authority = '%3' WHERE username='%1';").
                     arg(info.username).
                     arg(info.password).
                     arg(info.authority);
    return q.exec(strSql);
}

bool mysql::addUser(UserInfo info)
{
    QSqlQuery q(my_db);
    QString strSql = QString("INSERT INTO Username VALUES ('%1', '%2', '%3');").
                     arg(info.username).
                     arg(info.password).
                     arg(info.authority);
    return q.exec(strSql);
}

bool mysql::delUser(QString username)
{
    QSqlQuery q(my_db);
    QString strSql = QString("DELETE FROM Username WHERE username = '%1';").
                     arg(username);
    return q.exec(strSql);
}
