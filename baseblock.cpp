#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>

#include "baseblock.h"

BaseBlock::BaseBlock(BlockType blocktype, QString img, QMenu *contextMenu, QGraphicsItem *parent)
    :QGraphicsPixmapItem(QPixmap(img), parent)
{
    myBlockType = blocktype;
    myContextMenu = contextMenu;
}

BaseBlock::~BaseBlock()
{
    ;
}

// dumb method
bool BaseBlock::has_value()
{
    return true;
}

// dumb method
bool BaseBlock::is_computable()
{
    return true;
}

// dumb method
void BaseBlock::operation()
{
    ;
}

// dumb method
void BaseBlock::propagate()
{
    ;
}
