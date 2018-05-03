#include "blockitem.h"

BlockItem::BlockItem(BlockType blocktype, QPixmap &pixmap, QMenu *contextMenu, QGraphicsItem *parent)
    :BaseBlock(blocktype, pixmap, contextMenu, parent)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

BlockItem::~BlockItem()
{
    ;
}
