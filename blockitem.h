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

//    bool propagated;
    virtual void operation() = 0;
    bool is_computable() override;
    bool all_ports_used() override;

    std::vector<InputPort*> in_ports;
    OutputPort *out_port;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;
};

#endif // BLOCKITEM_H
