#include "port.h"
#include "connection.h"

Port::Port(PortType type, QGraphicsItem *parent)
    : QGraphicsPixmapItem(QPixmap(":port.png"), parent)
{
    myType = type;
}

Port::~Port()
{
    ;
}
