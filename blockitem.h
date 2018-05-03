#ifndef BLOCKITEM_H
#define BLOCKITEM_H

#include "baseblock.h"

class Port;
class InputPort;
class OutputPort;

class BlockItem : public BaseBlock
{
public:
    BlockItem(BlockType blocktype, QPixmap &pixmap, QMenu *contextMenu, QGraphicsItem *parent = 0);
    bool propagated;
    virtual void operation() = 0;
    bool is_computable;
    virtual ~BlockItem();
    std::vector<InputPort*> in_ports;
    OutputPort *out_port;
};

#endif // BLOCKITEM_H
