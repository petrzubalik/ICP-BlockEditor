#include "outputblock.h"
#include "port.h"
#include <QPainter>

OutputBlock::OutputBlock(QMenu *contextMenu, QGraphicsItem *parent)
    :BaseBlock(BaseBlock::OutputBlock, ":output.jpg", contextMenu, parent)
{
    textBlock = new TextBlock(this);
    textBlock->setTextWidth(100.0);
    textBlock->setPos(40,25);
    in_port = new InputPort(this);
    in_port->setPos(-10,25);
    showed = false;


    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

OutputBlock::~OutputBlock()
{
    ;
}


