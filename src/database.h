#ifndef DATABASE_H
#define DATABASE_H
#include <QObject>
#include <QSqlDatabase>

class DatabaseManager : public QObject {
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    void init();
private:
    QSqlDatabase m_db;
};
#endif
