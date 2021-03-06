/**
  * @file connection.cpp
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  The file implements methods from file connection.h
  *
  */

#include "connection.h"

#include <QPen>
#include <QPainter>
#include <iostream>
#include "port.h"


Connection::Connection(OutputPort *p1, InputPort *p2,
                       QGraphicsItem *parent)
    : QGraphicsLineItem(parent)
{
    source_port = p1;
    dest_port = p2;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setAcceptHoverEvents(true);
    setToolTip(QString("Unknown"));

    myColor = QColor(244, 147, 56);
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
    painter->setPen(myPen);
    painter->setBrush(myColor);

    QPointF p1 = source_port->scenePos();
    QPointF p2 = dest_port->scenePos();

    p1.setX(p1.rx() + 15);
    p1.setY(p1.ry() + 15);

    p2.setX(p2.rx() + 15);
    p2.setY(p2.ry() + 15);


    setLine(QLineF(p1, p2));
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
