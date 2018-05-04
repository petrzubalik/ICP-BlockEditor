#ifndef OUTPUTBLOCK_H
#define OUTPUTBLOCK_H

#include "baseblock.h"
#include "textblock.h"
#include <QPainter>

class OutputBlock : public BaseBlock
{
public:
    OutputBlock(QMenu *contextMenu, QGraphicsItem *parent = 0);
    ~OutputBlock();
    bool showed;
    InputPort *in_port;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;
};

#endif // OUTPUTBLOCK_H
