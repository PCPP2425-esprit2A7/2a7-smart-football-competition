#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
class connection
{
public:
    connection();
    bool createconnect();
};

#endif // CONNECTION_H



/*
class Connection {
public:

    Connection();
    bool createconnect();// ✅ Nom de fonction clair et respectant les conventions
};

#endif // CONNECTION_H
*/
