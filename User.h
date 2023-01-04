#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

#include "Location.h"
#include "defs.h"

using namespace std;

class User{

    public:
        User(char, int, const string&, int, Location);

    //getters
        string getId() const;
        string getName() const;
        Location getLocation() const;
        int getRating() const;

    //setters
        void setRating(int rating);
        void setLocation(Location l);
        void setLocation(int x, int y);

    //other
        void print() const;
        bool lessThan(User) const;
        bool matches(const string& name) const;

    protected:
        string id = "";
        string name = "";
        int rating = -1;
        Location location;

};

#endif 