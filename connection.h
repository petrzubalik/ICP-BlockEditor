#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsLineItem>

class Port;


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

    Connection(Port *source_port, Port *dest_port,
      QGraphicsItem *parent = 0);

    int type() const Q_DECL_OVERRIDE { return Type; }
    QRectF boundingRect() const Q_DECL_OVERRIDE;

    Port *get_source_port() const { return source_port; }
    Port *get_dest_port() const { return dest_port; }

    void updatePosition();
    ~Connection();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

private:
    QColor myColor;
    Port *source_port;
    Port *dest_port;
};

#endif // CONNECTION_H
