#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <iostream>
#include <string>

#include "defs.h"
#include "Customer.h"

using namespace std;

class CustomerList{


    class Node {

    public:
        Customer* data;
        Node*    next;
};

public:
    CustomerList();
    
    ~CustomerList();

    //other
    void add(Customer*);
    bool isEmpty() const;
    bool get(const string& name, Customer**) const;
    bool remove(const string& name, Customer**);
    void print() const;
    void clear();

private:
    Node* head;

};



#endif