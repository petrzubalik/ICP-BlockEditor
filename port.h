#ifndef PORT_H
#define PORT_H

#include "connection.h"

class Port : public QGraphicsPixmapItem
{
protected:
    static QPixmap pixmap;
    double value;
    bool used;
public:
    Port(QGraphicsItem *parent = 0);
    ~Port();
    bool has_value;
    double get_value();
    void set_value(double val);
    Connection *connection; // getter
//    void connect(Port *dest);
//    void disconnect();

};

#endif // PORT_H
