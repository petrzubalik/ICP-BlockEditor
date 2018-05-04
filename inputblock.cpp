#include "inputblock.h"
#include "port.h"
#include "textblock.h"

InputBlock::InputBlock(QMenu *contextMenu, QGraphicsItem *parent)
    : BaseBlock(BaseBlock::InputBlock, ":input.jpg", contextMenu, parent)
{
    textBlock = new TextBlock(this);
    textBlock->setTextWidth(100.0);
    textBlock->setPos(40, 25);
    OutputPort *p = new OutputPort(this);
    p->setPos(180, 30);

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}



