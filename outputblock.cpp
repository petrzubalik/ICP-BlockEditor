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

    QString text = QString::number(42.5);
    painter->drawText(40, -5, 100, 100, Qt::AlignCenter, text);

//    if (in_port->has_value)
//    {
//        QString text = QString::number(in_port->get_value());
//        painter->drawText(100, 40, 100, 100, Qt::AlignCenter, text);
//    }


}
