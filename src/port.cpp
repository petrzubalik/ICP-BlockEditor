/**
  * @file port.cpp
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  The file implements methods from file port.h
  *
  */

#include "port.h"
#include "connection.h"

Port::Port(PortType type, QGraphicsItem *parent)
    : QGraphicsPixmapItem(QPixmap("://images/port.png"), parent)
{
    myType = type;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

Port::~Port()
{
    ;
}


void Port::set_value(double val)
{
    value = val;
}

double Port::get_value()
{
    return value;
}


InputPort::InputPort(QGraphicsItem *parent)
    : Port(Port::Input, parent)
{
    connection = 0;
    used = false;
    has_value = false;

}


OutputPort::OutputPort(QGraphicsItem *parent)
    : Port(Port::Output, parent)
{
    used = false;
    has_value = false;
}

InputPort::~InputPort()
{
    ;
}

Connection* OutputPort::connect(InputPort *port)
{
    used = true;
    Connection *new_connection = new Connection(this, port);
    port->connection = new_connection;
    port->used = true;
    connections.push_back(new_connection);
    return new_connection;
}

OutputPort::~OutputPort()
{
    for (auto connection : connections)
    {
        delete connection;
    }
}
