#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsLineItem>

class Port;
class InputPort;
class OutputPort;


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

    Connection(OutputPort *source_port, InputPort *dest_port,
      QGraphicsItem *parent = 0);

    int type() const Q_DECL_OVERRIDE { return Type; }
    QRectF boundingRect() const Q_DECL_OVERRIDE;

    OutputPort *get_source_port() const { return source_port; }
    InputPort *get_dest_port() const { return dest_port; }

    void updatePosition();
    ~Connection();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

private:
    QColor myColor;
    OutputPort *source_port;
    InputPort *dest_port;
};

#endif // CONNECTION_H
