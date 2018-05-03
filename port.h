#ifndef PORT_H
#define PORT_H


#include <QVariant>
#include "connection.h"



class Port : public QGraphicsPixmapItem
{
public:
    enum { Type = UserType + 42 };
    enum PortType { Input, Output};
    bool has_value;
    bool used;

    Port(PortType type, QGraphicsItem *parent = 0);
    ~Port();

    double get_value();
    void set_value(double val);

    PortType portType() {return myType;}
    int type() const Q_DECL_OVERRIDE { return Type;}

//    void disconnect(Connection *connection) = 0;

protected:
    double value;
    PortType myType;
};



class InputPort : public Port
{
public:
    InputPort(QGraphicsItem *parent = 0);
    ~InputPort();
    Connection *connection;
//    void disconnect(Connection *connection);
};


class OutputPort : public Port
{
public:
    OutputPort(QGraphicsItem *parent = 0);
    ~OutputPort();
    std::vector<Connection*> connections;
    Connection* connect(InputPort *dest);
//    void disconnect(Connection *connection);
//    void disconnect_all();
};

#endif // PORT_H
