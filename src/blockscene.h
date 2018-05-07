/**
  * @file blockscene.h
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  Class that represents scene of the program
  *
  */

#ifndef BLOCKSCENE_H
#define BLOCKSCENE_H

#include <QGraphicsScene>
#include "blockitem.h"
#include "outputblock.h"
#include "inputblock.h"

class MainWindow;

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
QT_END_NAMESPACE


/**
 * @brief BlockScene inherits from QGraphicsScene
 */
class BlockScene : public QGraphicsScene
{
    Q_OBJECT
public:

    /**
     * @brief enum of the modes of work
     */
    enum Mode { InsertBlock, InsertLine, MoveBlock };

    /**
     * @brief BlockScene    constructor of the BlockScene instance
     * @param mWindow       pointer to MainWindow instance
     * @param itemMenu      pointer to QMenu
     * @param parent        pointer to it's parent
     */
    explicit BlockScene(MainWindow *mWindow, QMenu *itemMenu, QObject *parent = 0);

public slots:
    /**
     * @brief setMode sets the mode of inserting or moving
     * @param mode  type of work
     */
    void setMode(Mode mode);

    /**
     * @brief setItemType sets the type of block item
     * @param type  type of BlockItem
     */
    void setItemType(BaseBlock::BlockType type);

signals:
//    void itemInserted(BaseBlock *item);

    /**
     * @brief itemInserted signal itemInserted
     * @param item  type of block, that is inserted
     */
    void itemInserted(BlockItem *item);
    /**
     * @brief itemInserted signal itemInserted
     * @param item  type of block, that is inserted
     */
    void itemInserted(InputBlock *item);
    /**
     * @brief itemInserted signal itemInserted
     * @param item  type of block, that is inserted
     */
    void itemInserted(OutputBlock *item);

protected:
    /**
     * @brief mousePressEvent overriden method that handles mousepress events on the scene
     * @param mouseEvent    event on the scene
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    /**
     * @brief mouseMoveEvent overriden method that handles mousemove events on the scene
     * @param mouseEvent
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    /**
     * @brief mouseReleaseEvent overriden method that handles mouserelease events on the scene
     * @param mouseEvent
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;

private:
//    bool isItemChange(int type);
    /**
     * @brief myItemType    type of BlockItem
     */
    BlockItem::BlockType myItemType;
    /**
     * @brief myItemMenu    menu of items
     */
    QMenu *myItemMenu;
    /**
     * @brief myMode    mode of work
     */
    Mode myMode;
    /**
     * @brief leftButtonDown    if the left mouse button is pressed
     */
    bool leftButtonDown;
    /**
     * @brief startPoint start point of the drawing event
     */
    QPointF startPoint;
    /**
     * @brief line  line that is about to be drawn
     */
    QGraphicsLineItem *line;
    /**
     * @brief mainWindow    pointer to MainWindow instance
     */
    MainWindow *mainWindow;

};

#endif // BLOCKSCENE_H
