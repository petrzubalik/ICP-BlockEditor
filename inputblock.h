#ifndef INPUTBLOCK_H
#define INPUTBLOCK_H

#include <QGraphicsPixmapItem>
#include "textblock.h"


class InputBlock : public QGraphicsPixmapItem
{
public:
    InputBlock(QGraphicsItem *parent = 0);
private:
    TextBlock *textBlock;
};

#endif // INPUTBLOCK_H
