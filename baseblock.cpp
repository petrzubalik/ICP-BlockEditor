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
