#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include <iostream>
#include "blockscene.h"
#include "operations.h"
#include "inputblock.h"
#include "outputblock.h"
#include "port.h"

BlockScene::BlockScene(QMenu *itemMenu, QObject *parent)
    : QGraphicsScene(parent)
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
    BaseBlock *block;

    switch (myMode) {
        case InsertBlock:
            switch (myItemType)
            {
                case BaseBlock::Addition:
                    block = new Addition(myItemMenu);
                    break;
                case BaseBlock::InputBlock:
                    block = new InputBlock(myItemMenu);
                    break;
                case BaseBlock::Subtraction:
                    block = new Subtraction(myItemMenu);
                    break;
                case BaseBlock::Multiplication:
                    block = new Multiplication(myItemMenu);
                    break;
                case BaseBlock::Division:
                    block = new Division(myItemMenu);
                    break;
                case BaseBlock::OutputBlock:
                    block = new OutputBlock(myItemMenu);
                    break;
                default:
                    ;
            }

            addItem(block);
            block->setPos(mouseEvent->scenePos());
            emit itemInserted(block);
            break;
        case InsertLine:
            line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
                                        mouseEvent->scenePos()));
            line->setPen(QPen(QColor(244, 147, 56), 2));
            addItem(line);
            break;
    default:
        ;
    }
    QGraphicsScene::mousePressEvent(mouseEvent);

}

void BlockScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (myMode == InsertLine && line != 0) {
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    } else if (myMode == MoveBlock) {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
}

void BlockScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (line != 0 && myMode == InsertLine) {
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();

        removeItem(line);
        delete line;

        if (startItems.count() > 0 && endItems.count() > 0 &&
            startItems.first()->type() == Port::Type &&
            endItems.first()->type() == Port::Type &&
            startItems.first() != endItems.first())
        {
            OutputPort *source = qgraphicsitem_cast<OutputPort *>(startItems.first());
            InputPort *dest = qgraphicsitem_cast<InputPort *>(endItems.first());

            if (source->portType() == Port::Output &&
                dest->portType() == Port::Input)
            {
                if (!dest->used)
                {
                    Connection *connection;
                    connection = source->connect(dest);
                    connection->setZValue(-1000);
                    addItem(connection);
                    connection->updatePosition();
                }

            }
        }
    }
    line = 0;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}




