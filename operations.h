#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "blockitem.h"

class Addition : public BlockItem
{
public:
    Addition(QMenu *contextMenu, QGraphicsItem *parent = 0);
    void operation();
    ~Addition();

};

class Subtraction : public BlockItem
{
public:
    Subtraction(QMenu *contextMenu, QGraphicsItem *parent = 0);
    void operation();
    ~Subtraction();
};

class Multiplication : public BlockItem
{
public:
    Multiplication(QMenu *contextMenu, QGraphicsItem *parent = 0);
    void operation();
    ~Multiplication();
};

class Division : public BlockItem
{
public:
    Division(QMenu *contextMenu, QGraphicsItem *parent = 0);
    void operation();
    ~Division();
};

#endif // OPERATIONS_H
