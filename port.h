#ifndef PORT_H
#define PORT_H

#include "connection.h"

class Port
{
protected:
    double value;
    bool used;
public:
    Port();
    ~Port();
    bool has_value;
    double get_value();
    void set_value(double val);
    Connection *connection; // getter
//    void connect(Port *dest);
//    void disconnect();

};

#endif // PORT_H
