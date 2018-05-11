/**
  * @file outputblock.h
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  Class that represents output block
  *
  */

#ifndef OUTPUTBLOCK_H
#define OUTPUTBLOCK_H

#include "baseblock.h"
#include "textblock.h"
#include <QPainter>

/**
 * @brief The OutputBlock class inherits BaseBlock
 */
class OutputBlock : public BaseBlock
{
public:
    /**
     * @brief OutputBlock   constructor of the OutputBlock instances
     * @param contextMenu   menu for right mouse click action
     * @param parent        pointer to parent
     */
    OutputBlock(QMenu *contextMenu, QGraphicsItem *parent = 0);
    /**
      * @brief ~OutputBlock destructor
      */
    ~OutputBlock();
    /**
     * @brief showed flag if the result has been showed
     */
    bool showed;
    /**
     * @brief all_ports_used    overriden method that indicates if all ports are used
     * @return true if all ports are used, else false
     */
    bool all_ports_used() override;
    /**
     * @brief in_port pointer to input port
     */
    InputPort *in_port;

    std::vector<QPointF> connected_blocks;
    friend QDataStream &operator<<(QDataStream &out, OutputBlock* block);

protected:
    /**
     * @brief paint     overriden method that paints output block on the scene
     * @param painter   painter used for painting
     * @param option    option that is used for painting
     * @param widget    implicitly 0
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;
};

#endif // OUTPUTBLOCK_H
