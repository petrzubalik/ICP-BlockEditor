#ifndef OUTPUTBLOCK_H
#define OUTPUTBLOCK_H

#include "baseblock.h"
#include "textblock.h"


class OutputBlock : public BaseBlock
{
public:
    OutputBlock(QMenu *contextMenu, QGraphicsItem *parent = 0);
    ~OutputBlock();
    bool showed;
    InputPort *in_port;

private:
    TextBlock *textBlock;
};

#endif // OUTPUTBLOCK_H
