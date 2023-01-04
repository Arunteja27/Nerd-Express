#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>

#include "User.h"
#include "defs.h"

using namespace std;

class Driver: public User{

    public:
        Driver(const string& = "");
        Driver(const string& name, int rating, Size s, Location l);

        //other
        Location* staticLocation() const;
        bool match(int r, Size s) const;
        int getDistance(Location l);
        void print() const;

    private:
        Size size;
        static const char code = 'D';
        static int nextId;







};









#endif