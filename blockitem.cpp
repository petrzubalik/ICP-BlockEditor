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
    bool computable = true;

    for (InputPort *in_port: in_ports)

    {
        if (!in_port->used)
        {
            computable = false;
            break;
        }
    }
    return computable;
}
