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



class BaseBlock : public QGraphicsPixmapItem
{
public:
    enum { Type = UserType + 15 };
    enum BlockType { Addition, Subtraction, Multiplication, Division, InputBlock, OutputBlock };

    BaseBlock(BlockType blockType, QString img, QMenu *contextMenu, QGraphicsItem *parent = 0);

//    void removeConnection(Connection *connection);
//    void removeConnection();
    BlockType blockType() const { return myBlockType; }
//    void addConnection(Connection *connection);
//    QPixmap image() const;
    int type() const Q_DECL_OVERRIDE { return Type;}
    virtual ~BaseBlock();

protected:
   // void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;
   // QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;

private:
    BlockType myBlockType;
    QMenu *myContextMenu;
    QList<Connection *> connections;
};

#endif // BASEBLOCK_H
