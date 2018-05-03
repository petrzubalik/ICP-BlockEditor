#include "operations.h"
#include "port.h"

Addition::Addition(QPixmap pixmap, QMenu *contextMenu, QGraphicsItem *parent)
    : BlockItem(BaseBlock::Addition, pixmap, contextMenu, parent)
{
    Port *p1 = new Port(Port::Input, this);
    p1->setPos(0, 20);
    in_ports.push_back(p1);
    Port *p2 = new Port(Port::Input, this);
    p2->setPos(0, 70);
    in_ports.push_back(p2);

    Port *p3 = new Port(Port::Output, this);
    p3->setPos(135, 45);
    out_port = p3;

}

void Addition::operation()
{

    ;
}

Addition::~Addition()
{
    delete out_port;

    for (auto p: in_ports)
    {
        delete p;
    }
}
