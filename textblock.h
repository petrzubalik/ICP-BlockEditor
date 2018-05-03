#ifndef INPUTBLOCK_H
#define INPUTBLOCK_H

#include <QGraphicsTextItem>
#include <QPen>

QT_BEGIN_NAMESPACE
class QFocusEvent;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE


class TextBlock : public QGraphicsTextItem
{
    Q_OBJECT
public:
    enum { Type = UserType + 3};

    TextBlock(QGraphicsItem *parent = 0);

    int type() const Q_DECL_OVERRIDE { return Type; }

signals:
    void lostFocus(TextBlock *item);
    void selectedChange(QGraphicsItem *item);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;
    void focusOutEvent(QFocusEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // INPUTBLOCK_H
