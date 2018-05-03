#include "port.h"

QPixmap Port::pixmap = QPixmap(":port.png");

Port::Port(QGraphicsItem *parent)
    : QGraphicsPixmapItem(pixmap, parent){}

Port::~Port()
{
    ;
}
