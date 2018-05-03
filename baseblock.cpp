#include "baseblock.h"

BaseBlock::BaseBlock(BlockType blocktype, QPixmap &pixmap, QMenu *contextMenu, QGraphicsItem *parent)
    :QGraphicsPixmapItem(pixmap, parent)
{
    myBlockType = blocktype;
    myContextMenu = contextMenu;
}

BaseBlock::~BaseBlock()
{
    ;
}
