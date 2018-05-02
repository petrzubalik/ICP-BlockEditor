#include "blockitem.h"

BlockItem::BlockItem(BlockType blocktype, QMenu *contextMenu, QGraphicsItem *parent)
    :BaseBlock(blocktype, contextMenu, parent){}

BlockItem::~BlockItem()
{
    ;
}
