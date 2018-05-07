/**
  * @file baseblock.cpp
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  The file implements methods from file baseblock.h
  *
  */

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
