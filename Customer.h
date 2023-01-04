#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

#include "User.h"
#include "defs.h"

using namespace std;


class Customer: public User{

    public:
        //Customer();
        Customer(const string& = "");
        Customer(const string& name, int rating, Location l);

        //other
        void print() const;
        Location* staticLocation() const;

    private:
        static const char code = 'C';
        static int nextId;

};












#endif