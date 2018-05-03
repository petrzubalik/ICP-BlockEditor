#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include "blockscene.h"
#include "operations.h"

BlockScene::BlockScene(QMenu *itemMenu, QObject *parent)
{
    myItemMenu = itemMenu;
    myMode = MoveBlock;
    myItemType = BaseBlock::InputBlock;
    line = 0;
}


void BlockScene::setMode(Mode mode)
{
    myMode = mode;
}


void BlockScene::setItemType(BaseBlock::BlockType type)
{
    myItemType = type;
}


void BlockScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;
    BlockItem *block;
//    QGraphicsPixmapItem *block = new QGraphicsPixmapItem(QPixmap(":block_div.jpg"));
    switch (myMode) {
        case InsertBlock:
            switch (myItemType)
            {
                case BaseBlock::Addition:
                    block = new Addition(QPixmap(":block_div.jpg"), myItemMenu);
                break;
//                case BaseBlock::Subtraction:
//                    block = new Subtraction(myItemMenu);
//                break;
                default:
                    block = new Addition(QPixmap(":block_div.jpg"), myItemMenu);
            }
            addItem(block);
            block->setPos(mouseEvent->scenePos());
            emit itemInserted(block);
            break;
        case InsertLine:
            line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
                                        mouseEvent->scenePos()));


            addItem(line);
            break;
    default:
        ;
    }
}
