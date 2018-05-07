/**
  * @file blockitem.h
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  Class for representing block items
  *
  */

#ifndef BLOCKITEM_H
#define BLOCKITEM_H

#include "baseblock.h"

class Port;
class InputPort;
class OutputPort;


/**
 * @brief inherits from BaseBlock
 */
class BlockItem : public BaseBlock
{
public:
    /**
     * @brief constructor of BlockItem instances
     * @param blocktype     type of the instance
     * @param img           image of the given block
     * @param contextMenu   menu used for right mouse click action on the block
     * @param parent        parent of the BlockItem instance
     */
    BlockItem(BlockType blocktype, QString img, QMenu *contextMenu, QGraphicsItem *parent = 0);

    /**
     * @brief destructor of BlockItem instances
     */
    virtual ~BlockItem();

    /**
     * @brief flag saying if the block has propagated it's value
     */
    bool propagated;

    /**
     * @brief flag saying if the stepping mode is on
     */
    bool debug;

    /**
     * @brief pure virtual method of operation provided by the block
     */
    virtual void operation() = 0;

    /**
     * @brief   method that finds out if the block is computable
     * @return  true if the block is computable, else false
     */
    bool is_computable();

    std::vector<QPointF> connected_blocks;
    friend QDataStream &operator<<(QDataStream &out, BlockItem* block);

    /**
     * @brief   method detecting if all ports of the block are used
     * @return  true if all ports are used, else false
     */
    bool all_ports_used() override;

    /**
     * @brief vector that contains pointers to all input ports of the block
     */
    std::vector<InputPort*> in_ports;
    /**
     * @brief pointer pointing to output port
     */
    OutputPort *out_port;
protected:
    /**
     * @brief overriden method that paints block items on the scene
     * @param painter   painter used for painting
     * @param option    option that is used for painting
     * @param widget    implicitly 0
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;
};

#endif // BLOCKITEM_H
