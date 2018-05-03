#ifndef BLOCKITEM_H
#define BLOCKITEM_H

#include "baseblock.h"

class Port;

class BlockItem : public BaseBlock
{
public:
    BlockItem(BlockType blocktype, QPixmap &pixmap, QMenu *contextMenu, QGraphicsItem *parent = 0);
    bool propagated;
    virtual void operation() = 0;
    bool is_computable;
    virtual ~BlockItem();
protected:
    std::vector<Port*> in_ports;
    Port *out_port;
};

#endif // BLOCKITEM_H
