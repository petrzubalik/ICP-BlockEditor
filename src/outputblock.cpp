/**
  * @file outputblock.cpp
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  The file implements methods from file outputblock.h
  *
  */

#include "outputblock.h"
#include "port.h"
#include <QPainter>
#include <QFont>
#include <QGraphicsItem>
#include <QPen>

OutputBlock::OutputBlock(QMenu *contextMenu, QGraphicsItem *parent)
    :BaseBlock(BaseBlock::OutputBlock, ":output.jpg", contextMenu, parent)
{
    in_port = new InputPort(this);
    in_port->setPos(-10,25);
    showed = false;


    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

}

OutputBlock::~OutputBlock()
{
    ;
}


void OutputBlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *options,
          QWidget *widget)
{

    QGraphicsPixmapItem::paint(painter, options, widget);
    QFont font = painter->font();
    font.setPixelSize(24);
    painter->setFont(font);

    if (in_port->has_value)
    {
        QString text = QString::number(in_port->get_value());
        painter->drawText(40, -5, 100, 100, Qt::AlignCenter, text);
    }

//    QPainterPath path;
//    path.addRoundRect(boundingRect(), 0);
//    QPen myPen(Qt::blue, 10);
//    painter->setPen(myPen);
//    painter->drawPath(path);
}

bool OutputBlock::all_ports_used()
{
    return in_port->used;
}



