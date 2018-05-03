#include "connection.h"

#include <QPen>
#include <QPainter>
#include "port.h"


Connection::Connection(Port *p1, Port *p2,
                       QGraphicsItem *parent)
    : QGraphicsLineItem(parent)
{
    source_port = p1;
    dest_port = p2;
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    myColor = QColor(244, 147, 56); // ?????? TODO
    setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}


QRectF Connection::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}


void Connection::updatePosition()
{
    QLineF line(mapFromItem(source_port, 0, 0), mapFromItem(dest_port, 0, 0));
    setLine(line);
}


void Connection::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
          QWidget *)
{
    if (source_port->collidesWithItem(dest_port))
        return;

    QPen myPen = pen();
    myPen.setColor(myColor);
    qreal arrowSize = 20;
    painter->setPen(myPen);
    painter->setBrush(myColor);

    QLineF centerLine(source_port->pos(), dest_port->pos());
    setLine(centerLine);

    painter->drawLine(line());
    if (isSelected()) {
        painter->setPen(QPen(myColor, 1, Qt::DashLine));
        QLineF myLine = line();
        myLine.translate(0, 4.0);
        painter->drawLine(myLine);
        myLine.translate(0,-8.0);
        painter->drawLine(myLine);
    }
}

Connection::~Connection()
{
    ;
}
