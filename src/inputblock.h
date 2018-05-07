/**
  * @file inputblock.h
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  Class that represents input block
  *
  */

#ifndef INPUTBLOCK_H
#define INPUTBLOCK_H

#include "baseblock.h"
#include "textblock.h"


/**
 * @brief The InputBlock class inherits from BaseBlock
 */
class InputBlock : public BaseBlock
{
public:
    /**
     * @brief propagated indicating if the value from the block was propagated
     */
    bool propagated;
    /**
     * @brief has_value finding out if the block has value
     * @return  true if the block has value, else false
     */
    bool has_value();
    /**
     * @brief propagate propagates the value to next blocks
     */
    void propagate();
    /**
     * @brief out_port  pointer to the output port
     */
    OutputPort *out_port;
    /**
     * @brief all_ports_used    overriden method indicating if all ports are used
     * @return true if all ports are used, else false
     */
    bool all_ports_used() override;

    /**
     * @brief InputBlock    constructor of InputBlock instances
     * @param contextMenu   menu for right mouse click action
     * @param parent        pointer to parent
     */
    InputBlock(QMenu *contextMenu, QGraphicsItem *parent = 0);

    std::vector<QPointF> connected_blocks;
    friend QDataStream &operator<<(QDataStream &out, InputBlock* block);


private:
    /**
     * @brief textBlock pointer to textBlock which is placed on the InputBlock
     */
    TextBlock *textBlock;
};

#endif // INPUTBLOCK_H
