#ifndef DRIVERLIST_H
#define DRIVERLIST_H

#include <iostream>
#include <string>

#include "defs.h"
#include "Driver.h"

using namespace std;

class DriverList{

    class Node {

    public:
        Driver* data;
        Node*    next;
};

public:
    DriverList();
    ~DriverList();

    //other
    void add(Driver*);
    bool isEmpty() const;
    bool get(const string& name, Driver**) const;
    bool remove(const string& name, Driver**);
    bool findRide(int rating, Size s, Location l, Driver** d);
    void print() const;
    void clear();

private:
    Node* head;
    int size;

};



#endif