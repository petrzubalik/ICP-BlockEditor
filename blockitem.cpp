#include "blockitem.h"
#include "port.h"

BlockItem::BlockItem(BlockType blocktype, QString img, QMenu *contextMenu, QGraphicsItem *parent)
    :BaseBlock(blocktype, img, contextMenu, parent)
{
    propagated = false;

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

BlockItem::~BlockItem()
{
    ;
}

bool BlockItem::is_computable()
{

    for (InputPort *in_port: in_ports)
    {
        if (!in_port->has_value)
        {
            return false;
        }
    }
    return true;
}


bool BlockItem::all_ports_used()
{
    if (!out_port->used)
    {
        return false;
    }

    for (InputPort *port : in_ports)
    {
        if (!port->used)
        {
            return false;
        }
    }
    return true;
}
