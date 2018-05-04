#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include <iostream>
#include "blockscene.h"
#include "operations.h"
#include "inputblock.h"
#include "outputblock.h"
#include "port.h"
#include "mainwindow.h"

BlockScene::BlockScene(MainWindow *mWindow, QMenu *itemMenu, QObject *parent)
    : QGraphicsScene(parent)
{

    myItemMenu = itemMenu;
    myMode = MoveBlock;
    myItemType = BaseBlock::InputBlock;
    line = 0;
    mainWindow = mWindow;
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
                    mainWindow->operation_blocks.push_back(block);
                    break;
                case BaseBlock::InputBlock:
                    block = new InputBlock(myItemMenu);
                    mainWindow->input_blocks.push_back(block);
                    break;
                case BaseBlock::Subtraction:
                    block = new Subtraction(myItemMenu);
                    mainWindow->operation_blocks.push_back(block);
                    break;
                case BaseBlock::Multiplication:
                    block = new Multiplication(myItemMenu);
                    mainWindow->operation_blocks.push_back(block);
                    break;
                case BaseBlock::Division:
                    block = new Division(myItemMenu);
                    mainWindow->operation_blocks.push_back(block);
                    break;
                case BaseBlock::OutputBlock:
                    block = new OutputBlock(myItemMenu);
                    mainWindow->output_blocks.push_back(block);
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
//    [DEBUG]
//    std::cout << "operation blocks = " << mainWindow->operation_blocks.size() << std::endl;
//    std::cout << "input blocks = " << mainWindow->input_blocks.size() << std::endl;
//    std::cout << "out blocks = " << mainWindow->output_blocks.size() << std::endl << std::endl;

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




