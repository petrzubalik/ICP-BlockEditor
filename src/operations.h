/**
  * @file operations.h
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  Classes that represents operations provided by block items
  *
  */

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "blockitem.h"


/**
 * @brief The Addition class inherits from BlockItem and provides addition operation
 */
class Addition : public BlockItem
{
public:
    /**
     * @brief Addition      constructor of the Addition instances
     * @param contextMenu   menu for right mouse click action
     * @param parent        pointer to parent, implicitly 0
     */
    Addition(QMenu *contextMenu, QGraphicsItem *parent = 0);
    /**
     * @brief operation method that provides compute operation
     */
    void operation();
    /**
      * @brief ~Addition destructor of the Addition instances
      */
    ~Addition();

};

/**
 * @brief The Subtraction class inherits from BlockItem and provides addition operation
 */
class Subtraction : public BlockItem
{
public:
    /**
     * @brief Addition      constructor of the Subtraction instances
     * @param contextMenu   menu for right mouse click action
     * @param parent        pointer to parent, implicitly 0
     */
    Subtraction(QMenu *contextMenu, QGraphicsItem *parent = 0);
    /**
     * @brief operation method that provides compute operation
     */
    void operation();
    /**
      * @brief ~Subtraction destructor of Subtraction instances
      */
    ~Subtraction();
};


/**
 * @brief The Multiplication class inherits from BlockItem and provides addition operation
 */
class Multiplication : public BlockItem
{
public:
    /**
     * @brief Multiplication    constructor of the Multiplication instances
     * @param contextMenu       menu for right mouse click action
     * @param parent            pointer to parent, implicitly 0
     */
    Multiplication(QMenu *contextMenu, QGraphicsItem *parent = 0);
    /**
     * @brief operation method that provides compute operation
     */
    void operation();
    /**
      * @brief ~Multiplication  destructor of Multiplication instances
      */
    ~Multiplication();
};


/**
 * @brief The Division class inherits from BlockItem and provides addition operation
 */
class Division : public BlockItem
{
public:
    /**
     * @brief Division      constructor of the Division instances
     * @param contextMenu   menu for right mouse click action
     * @param parent        pointer to parent, implicitly 0
     */
    Division(QMenu *contextMenu, QGraphicsItem *parent = 0);
    /**
     * @brief operation method that provides compute operation
     */
    void operation();
    /**
      * @brief ~Division   destructor of Multiplication instances
      */
    ~Division();
};

#endif // OPERATIONS_H
