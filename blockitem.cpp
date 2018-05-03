#include "blockitem.h"

BlockItem::BlockItem(BlockType blocktype, QPixmap &pixmap, QMenu *contextMenu, QGraphicsItem *parent)
    :BaseBlock(blocktype, pixmap, contextMenu, parent){}

BlockItem::~BlockItem()
{
    ;
}
