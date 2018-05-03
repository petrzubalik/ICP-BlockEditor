#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "blockitem.h"

class Addition : public BlockItem
{
public:
    Addition(QMenu *contextMenu, QGraphicsItem *parent = 0);
    void operation();
    ~Addition();
};

#endif // OPERATIONS_H
