#ifndef BLOCKITEM_H
#define BLOCKITEM_H

#include "baseblock.h"

class Port;
class InputPort;
class OutputPort;

class BlockItem : public BaseBlock
{
public:
    BlockItem(BlockType blocktype, QString img, QMenu *contextMenu, QGraphicsItem *parent = 0);
    virtual ~BlockItem();

    bool propagated;
    virtual void operation() = 0;
    bool is_computable();
    bool all_ports_used();

    std::vector<InputPort*> in_ports;
    OutputPort *out_port;
};

#endif // BLOCKITEM_H
