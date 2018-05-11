/**
  * @file baseblock.h
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  Base class for blocks
  *
  */


#ifndef BASEBLOCK_H
#define BASEBLOCK_H

#include <QGraphicsPixmapItem>
#include <QList>
#include "connection.h"

QT_BEGIN_NAMESPACE
class QPixmap;
class QGraphicsItem;
class QGraphicsScene;
class QTextEdit;
class QGraphicsSceneMouseEvent;
class QMenu;
class QGraphicsSceneContextMenuEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QPolygonF;
QT_END_NAMESPACE


/**
 * @brief inherits from QGraphicsPixmapItem
 *
 */
class BaseBlock : public QGraphicsPixmapItem
{
public:
    /**
     * @brief Used for identifying the class
     */
    enum { Type = UserType + 15 };
    /**
     * @brief The BlockType enum - used for recognition of block types
     */
    enum BlockType { Addition, Subtraction, Multiplication, Division, InputBlock, OutputBlock };

    /**
     * @brief BaseBlock     constructor of BaseBlock instances
     * @param blockType     type of block item
     * @param img           image of the given block
     * @param contextMenu   for mouse right click on the block
     * @param parent        parent of the BaseBlock instance
     */
    BaseBlock(BlockType blockType, QString img, QMenu *contextMenu, QGraphicsItem *parent = 0);

    /**
     * @brief ~BaseBlock    destructor of BaseBlock instances
     */
    virtual ~BaseBlock();

    /**
     * @brief blockType
     * @return              the type of block item
     */
    BlockType blockType() const { return myBlockType; }

    /**
     * @brief type          method that returns BaseBlock class type
     * @return              BaseBlock type
     */
    int type() const Q_DECL_OVERRIDE { return Type;}

    /**
     * @brief all_ports_used    pure virtual method
     * @return                  true if all ports are used, else false
     */
    virtual bool all_ports_used() = 0;


protected:
   // void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;
   // QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;

private:
    /**
     * @brief myBlockType   stores type of the block item
     */
    BlockType myBlockType;
    /**
     * @brief myContextMenu used for the mouse right click on the block item
     */
    QMenu *myContextMenu;
    /**
     * @brief connections   list of connections, that connect the block item with other blocks
     */
    QList<Connection *> connections;
};

#endif // BASEBLOCK_H
