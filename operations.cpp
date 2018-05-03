#include "operations.h"
#include "port.h"

Addition::Addition(QPixmap pixmap, QMenu *contextMenu, QGraphicsItem *parent)
    : BlockItem(BaseBlock::Addition, pixmap, contextMenu, parent)
{
    Port *p1 = new Port(this);
    p1->setPos(0, 20);
    in_ports.push_back(p1);
    Port *p2 = new Port(this);
    p2->setPos(0, 20);
    in_ports.push_back(p2);

    Port *p3 = new Port(this);
    p3->setPos(100, 50);
    out_port = p3;
}

void Addition::operation()
{
    ;
}

Addition::~Addition()
{
    ;
}
