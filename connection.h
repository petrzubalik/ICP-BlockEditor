#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsLineItem>
#include "blockitem.h"

class BlockItem;

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
QT_END_NAMESPACE

class Connection : public QGraphicsLineItem
{
public:
    enum { Type = UserType + 4 };

    Connection(BlockItem *startItem, BlockItem *endItem,
      QGraphicsItem *parent = 0);

    int type() const Q_DECL_OVERRIDE { return Type; }
    QRectF boundingRect() const Q_DECL_OVERRIDE;
//    QPainterPath shape() const Q_DECL_OVERRIDE;

    BlockItem *startItem() const { return myStartItem; }
    BlockItem *endItem() const { return myEndItem; }

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

private:
    BlockItem *myStartItem;
    BlockItem *myEndItem;
};

#endif // CONNECTION_H
