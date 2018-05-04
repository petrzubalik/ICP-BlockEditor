#include "blockitem.h"

BlockItem::BlockItem(BlockType blocktype, QString img, QMenu *contextMenu, QGraphicsItem *parent)
    :BaseBlock(blocktype, img, contextMenu, parent)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

BlockItem::~BlockItem()
{
    ;
}
