/**
  * @file connection.h
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  Class that represents connection between two blocks
  *
  */

#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsLineItem>

class Port;
class InputPort;
class OutputPort;


class BlockItem;

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
QT_END_NAMESPACE


/**
 * @brief The Connection class inherits from QGraphicsLineItem
 */
class Connection : public QGraphicsLineItem
{
public:
    /**
     * Type for representing the class
     */
    enum { Type = UserType + 4 };

    /**
     * @brief Connection    constructor of Connection instances
     * @param source_port   pointer to source port
     * @param dest_port     pointer to destination port
     * @param parent        pointer to parent
     */
    Connection(OutputPort *source_port, InputPort *dest_port,
      QGraphicsItem *parent = 0);
    /**
      * @brief destructor of the Connection instances
      */
    ~Connection();

    /**
     * @brief type  getter for Connection class type
     * @return  type of Connection class
     */
    int type() const Q_DECL_OVERRIDE { return Type; }
    /**
     * @brief boundingRect  overrides method of QGraphicsLine that defines rectangle around the connection
     * @return  QRectF type representing rectangle arround the connection
     */
    QRectF boundingRect() const Q_DECL_OVERRIDE;

    /**
     * @brief get_source_port   getter for pointer to source port
     * @return  pointer to OutputPort
     */
    OutputPort *get_source_port() const { return source_port; }

    /**
     * @brief get_dest_port getter for pointer to destination port
     * @return pointer to InputPort
     */
    InputPort *get_dest_port() const { return dest_port; }

    /**
     * @brief updatePosition    updates position of the connection
     */
    void updatePosition();

protected:
    /**
     * @brief paint     overriden method that paints connections on the scene
     * @param painter   painter used for painting
     * @param option    option that is used for painting
     * @param widget    implicitly 0
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

private:
    /**
     * @brief myColor   color of the connection
     */
    QColor myColor;
    /**
     * @brief source_port   pointer to the source port
     */
    OutputPort *source_port;
    /**
     * @brief dest_port pointer to the destination port
     */
    InputPort *dest_port;
};

#endif // CONNECTION_H
