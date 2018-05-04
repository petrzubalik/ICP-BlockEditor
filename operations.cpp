#include "operations.h"
#include "port.h"

Addition::Addition(QMenu *contextMenu, QGraphicsItem *parent)
    : BlockItem(BaseBlock::Addition, ":add_block.jpg", contextMenu, parent)
{
    InputPort *p1 = new InputPort(this);
    p1->setPos(-10, 20);
    p1->setZValue(1000);
    in_ports.push_back(p1);
    InputPort *p2 = new InputPort(this);
    p2->setPos(-10, 70);
    p2->setZValue(1000);
    in_ports.push_back(p2);

    OutputPort *p3 = new OutputPort(this);
    p3->setPos(155, 45);
    p3->setZValue(1000);
    out_port = p3;

}

void Addition::operation()
{


    double op1 = in_ports[0]->get_value();
    double op2 = in_ports[1]->get_value();

    double result = op1 + op2;

    for (Connection *connection : out_port->connections)
    {
        InputPort *dest_port = connection->get_dest_port();

        dest_port->set_value(result);
        dest_port->has_value = true;
    }
}

Addition::~Addition()
{
    delete out_port;

    for (auto p: in_ports)
    {
        delete p;
    }
}


Subtraction::Subtraction(QMenu *contextMenu, QGraphicsItem *parent)
    : BlockItem(BaseBlock::Subtraction, ":sub_block.jpg", contextMenu, parent)
{
    InputPort *p1 = new InputPort(this);
    p1->setPos(-10, 20);
    p1->setZValue(1000);
    in_ports.push_back(p1);
    InputPort *p2 = new InputPort(this);
    p2->setPos(-10, 70);
    p2->setZValue(1000);
    in_ports.push_back(p2);

    OutputPort *p3 = new OutputPort(this);
    p3->setPos(155, 45);
    p3->setZValue(1000);
    out_port = p3;
}

void Subtraction::operation()
{
    double op1 = in_ports[0]->get_value();
    double op2 = in_ports[1]->get_value();

    double result = op1 - op2;

    for (Connection *connection : out_port->connections)
    {
        InputPort *dest_port = connection->get_dest_port();

        dest_port->set_value(result);
        dest_port->has_value = true;
    }
}

Subtraction::~Subtraction()
{
    ;
}


Multiplication::Multiplication(QMenu *contextMenu, QGraphicsItem *parent)
    : BlockItem(BaseBlock::Multiplication, ":mul_block.jpg", contextMenu, parent)
{
    InputPort *p1 = new InputPort(this);
    p1->setPos(-10, 20);
    p1->setZValue(1000);
    in_ports.push_back(p1);
    InputPort *p2 = new InputPort(this);
    p2->setPos(-10, 70);
    p2->setZValue(1000);
    in_ports.push_back(p2);

    OutputPort *p3 = new OutputPort(this);
    p3->setPos(155, 45);
    p3->setZValue(1000);
    out_port = p3;
}

void Multiplication::operation()
{
    double op1 = in_ports[0]->get_value();
    double op2 = in_ports[1]->get_value();

    double result = op1 * op2;

    for (Connection *connection : out_port->connections)
    {
        InputPort *dest_port = connection->get_dest_port();

        dest_port->set_value(result);
        dest_port->has_value = true;
    }
}

Multiplication::~Multiplication()
{
    ;
}

Division::Division(QMenu *contextMenu, QGraphicsItem *parent)
    : BlockItem(BaseBlock::Division, ":div_block.jpg", contextMenu, parent)
{
    InputPort *p1 = new InputPort(this);
    p1->setPos(-10, 20);
    p1->setZValue(1000);
    in_ports.push_back(p1);
    InputPort *p2 = new InputPort(this);
    p2->setPos(-10, 70);
    p2->setZValue(1000);
    in_ports.push_back(p2);

    OutputPort *p3 = new OutputPort(this);
    p3->setPos(155, 45);
    p3->setZValue(1000);
    out_port = p3;
}

void Division::operation()
{
    double op1 = in_ports[0]->get_value();
    double op2 = in_ports[1]->get_value();

    if (op2 == 0)
    {
        throw std::logic_error("Division by zero!");
    }

    double result = op1 / op2;

    for (Connection *connection : out_port->connections)
    {
        InputPort *dest_port = connection->get_dest_port();

        dest_port->set_value(result);
        dest_port->has_value = true;
    }
}


Division::~Division()
{
    ;
}



