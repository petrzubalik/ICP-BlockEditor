#include "operations.h"
#include "port.h"

Addition::Addition(QMenu *contextMenu, QGraphicsItem *parent)
    : BlockItem(BaseBlock::Addition, ":block_div.jpg", contextMenu, parent)
{
    InputPort *p1 = new InputPort(this);
    p1->setPos(-5, 20);
    p1->setZValue(1000);
    in_ports.push_back(p1);
    InputPort *p2 = new InputPort(this);
    p2->setPos(-5, 70);
    p2->setZValue(1000);
    in_ports.push_back(p2);

    OutputPort *p3 = new OutputPort(this);
    p3->setPos(140, 45);
    p3->setZValue(1000);
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
