#include "inputblock.h"
#include "port.h"
#include "textblock.h"

InputBlock::InputBlock(QMenu *contextMenu, QGraphicsItem *parent)
    : BaseBlock(BaseBlock::InputBlock, ":input.jpg", contextMenu, parent)
{
    textBlock = new TextBlock(this);
    textBlock->setTextWidth(100.0);
    textBlock->setPos(40, 25);
    out_port = new OutputPort(this);
    out_port->setPos(168, 25);

    propagated = false;

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}


bool InputBlock::has_value()
{
    QString text = textBlock->toPlainText();
    if (text.isEmpty())
    {
        return false;
    }

    bool conversion = false;
    double value = text.toDouble(&conversion);

    if (conversion == false)
    {
        ;
    } else
    {
        out_port->set_value(value);
        out_port->has_value = true;
    }

    return conversion;
}


void InputBlock::propagate()
{
    InputPort *dest_port;

    for (Connection * connection: out_port->connections)
    {
        dest_port = connection->get_dest_port();
        dest_port->has_value = true;
        dest_port->set_value(out_port->get_value());
    }

    propagated = true;
}

bool InputBlock::all_ports_used()
{
    return out_port->used;
}



