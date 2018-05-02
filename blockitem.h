#ifndef BLOCKITEM_H
#define BLOCKITEM_H

#include "baseblock.h"

class Port;

class BlockItem : public BaseBlock
{
public:
    BlockItem(BlockType blocktype, QMenu *contextMenu, QGraphicsItem *parent = 0);
    bool propagated;
    void operation();
    bool is_computable;
    ~BlockItem();
protected:
    std::vector<Port*> in_ports;
    Port *out_port;
};

#endif // BLOCKITEM_H
