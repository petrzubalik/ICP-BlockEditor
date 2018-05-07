/**
  * @file textblock.h
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  Class that represents textblock placed on the input block
  *
  */

#ifndef TEXTBLOCK_H
#define TEXTBLOCK_H

#include <QGraphicsTextItem>
#include <QPen>

QT_BEGIN_NAMESPACE
class QFocusEvent;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

/**
 * @brief The TextBlock class inherits from QGraphicsTextItem and represents text blocks on the input blocks
 */
class TextBlock : public QGraphicsTextItem
{
    Q_OBJECT
public:
    /**
     * @brief Type represents type of the TextBlock class
     */
    enum { Type = UserType + 3};

    /**
     * @brief TextBlock constructor of the TextBlock instances
     * @param parent    pointer to parent
     */
    TextBlock(QGraphicsItem *parent = 0);
    /**
     * @brief type returns Type of TextBlock class
     * @return type of TextBlock class
     */
    int type() const Q_DECL_OVERRIDE { return Type; }

signals:
    /**
     * @brief lostFocus signal that indicates that texBlock lost focus
     * @param item  pointer to TextBlock
     */
    void lostFocus(TextBlock *item);
    /**
     * @brief selectedChange signal that indicates that selected has changed
     * @param item  pointer to QGraphicsItem
     */
    void selectedChange(QGraphicsItem *item);

protected:
    /**
     * @brief itemChange    overriden method invoked when item in the block has changed
     * @param change        change of the item
     * @param value         value of the block
     * @return              QVariant
     */
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;

    /**
     * @brief focusOutEvent overriden method that is invoked if the block is unfocused
     * @param event
     */
    void focusOutEvent(QFocusEvent *event) Q_DECL_OVERRIDE;

    /**
     * @brief mouseDoubleClickEvent overriden method that handles mousedoubleclick event
     * @param event
     */
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // INPUTBLOCK_H
