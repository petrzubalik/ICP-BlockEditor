/**
  * @file port.h
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  Classes that represents ports
  *
  */

#ifndef PORT_H
#define PORT_H


#include <QVariant>
#include "connection.h"


/**
 * @brief The Port class inherits from QGraphicsPixmapItem and represents port on the block
 */
class Port : public QGraphicsPixmapItem
{
public:
    /**
     * @brief enum representing type of class Port
     */
    enum { Type = UserType + 42 };
    /**
     * @brief The PortType enum represents type of port
     */
    enum PortType { Input, Output};
    /**
     * @brief has_value flag indicating if the port has value
     */
    bool has_value;
    /**
     * @brief used flag indicating if the port is connected to another port
     */
    bool used;


    /**
     * @brief Port      constructor of the Port instances
     * @param type      type of port
     * @param parent    pointer to parent
     */
    Port(PortType type, QGraphicsItem *parent = 0);
    /**
      * @brief ~Port destructor of Port instances
      */
    ~Port();

    /**
     * @brief   get_value getter for the port value
     * @return  value stored in the port
     */
    double get_value();
    /**
     * @brief set_value setter of the value stored in the port
     * @param val       value that is about to be stored in the port
     */
    void set_value(double val);

    /**
     * @brief portType getter for the port type
     * @return  port type
     */
    PortType portType() {return myType;}
    /**
     * @brief type return the Type of Port class
     * @return  Type of Port class
     */
    int type() const Q_DECL_OVERRIDE { return Type;}

//    void disconnect(Connection *connection) = 0;

protected:
    /**
     * @brief value value that is stored in the port
     */
    double value;
    /**
     * @brief myType port type
     */
    PortType myType;
};


/**
 * @brief The InputPort class inherits from Port and represents input port
 */
class InputPort : public Port
{
public:
    /**
     * @brief InputPort construcot of InputPort instances
     * @param parent    pointer to parent
     */
    InputPort(QGraphicsItem *parent = 0);
    /**
      * @brief  ~InputPort  destructor
      */
    ~InputPort();
    /**
     * @brief connection connection connected to the port
     */
    Connection *connection;
//    void disconnect(Connection *connection);
};

/**
 * @brief The OutputPort class inherits from Port and represents ouput port
 */
class OutputPort : public Port
{
public:
    /**
     * @brief OutputPort    constructor of the OutputPort instances
     * @param parent        pointer to parent
     */
    OutputPort(QGraphicsItem *parent = 0);
    /**
      * @brief ~OutputPort  destructor
      */
    ~OutputPort();
    /**
     * @brief connections vector of connections connected to the port
     */
    std::vector<Connection*> connections;
    /**
     * @brief connect function that connects port and connection
     * @param dest
     * @return pointer to connection
     */
    Connection* connect(InputPort *dest);
//    void disconnect(Connection *connection);
//    void disconnect_all();
};

#endif // PORT_H
