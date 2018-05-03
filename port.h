#ifndef PORT_H
#define PORT_H


#include <QVariant>
#include "connection.h"



class Port : public QGraphicsPixmapItem
{
public:
    enum { Type = UserType + 42 };
    enum PortType { Input, Output};

    Port(PortType type, QGraphicsItem *parent = 0);
    ~Port();

    bool has_value;

    double get_value();
    void set_value(double val);

    PortType portType() {return myType;}

    int type() const Q_DECL_OVERRIDE { return Type;}

    Connection *connection; // getter
//    void connect(Port *dest);
//    void disconnect();

protected:
    double value;
    bool used;
    PortType myType;

};

#endif // PORT_H
