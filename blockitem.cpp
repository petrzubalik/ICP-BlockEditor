#include <QPen>
#include <QPainter>
#include "blockitem.h"
#include "port.h"

BlockItem::BlockItem(BlockType blocktype, QString img, QMenu *contextMenu, QGraphicsItem *parent)
    :BaseBlock(blocktype, img, contextMenu, parent)
{
    propagated = false;

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

BlockItem::~BlockItem()
{
    ;
}

bool BlockItem::is_computable()
{

    for (InputPort *in_port: in_ports)
    {
        if (!in_port->has_value)
        {
            return false;
        }
    }
    return true;
}


bool BlockItem::all_ports_used()
{
    if (!out_port->used)
    {
        return false;
    }

    for (InputPort *port : in_ports)
    {
        if (!port->used)
        {
            return false;
        }
    }
    return true;
}

void BlockItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *options,
          QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, options, widget);
    if (debug && propagated)
    {
        QPainterPath path;
        path.addRoundRect(boundingRect(), 0);
        QPen myPen(Qt::blue, 10);
        painter->setPen(myPen);
        painter->drawPath(path);

        QFont font = painter->font();
        font.setPixelSize(24);
        painter->setFont(font);
        QString text = QString::number(out_port->get_value());
        painter->drawText(40, -5, 100, 100, Qt::AlignCenter, text);
    }
}



