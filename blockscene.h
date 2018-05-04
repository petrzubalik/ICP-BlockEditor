#ifndef BLOCKSCENE_H
#define BLOCKSCENE_H

#include <QGraphicsScene>
#include "blockitem.h"


QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
QT_END_NAMESPACE


class BlockScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum Mode { InsertBlock, InsertLine, MoveBlock };

    explicit BlockScene(QMenu *itemMenu, QObject *parent = 0);

public slots:
    void setMode(Mode mode);
    void setItemType(BaseBlock::BlockType type);

signals:
    void itemInserted(BaseBlock *item);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;

private:
//    bool isItemChange(int type);

    BlockItem::BlockType myItemType;
    QMenu *myItemMenu;
    Mode myMode;
    bool leftButtonDown;
    QPointF startPoint;
    QGraphicsLineItem *line;

};

#endif // BLOCKSCENE_H
