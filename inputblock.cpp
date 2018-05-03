#include "inputblock.h"
#include "port.h"
#include "textblock.h"

InputBlock::InputBlock(QGraphicsItem *parent)
    : QGraphicsPixmapItem(QPixmap(":input.jpg"), parent)
{
    textBlock = new TextBlock(this);
    textBlock->setTextWidth(100.0);
    OutputPort *p = new OutputPort(this);
    p->setPos(180, 30);
}



