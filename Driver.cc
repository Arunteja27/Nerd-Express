#include "Driver.h"

int Driver::nextId = 0;

//Create and return a statically created Location object pointer, for use in the default constructor
Location* Driver::staticLocation() const{
    Location* l;
    return l;
}

Driver::Driver(const string& name): size(small), User(code, -1, name, -1, *staticLocation()){
    
}

Driver::Driver(const string& n, int r, Size s, Location l):User(code, nextId++, n, r, l), size(s)
{

}

bool Driver::match(int r, Size s) const{
    if(s == small){
        if(size == small || size == medium || size == large){
            if(abs(rating - r)  <= 2){
                return true;
            }
        }
    }else if(s == medium){
        if(size == medium || size == large){
            if(abs(rating - r)  <= 2){
                return true;
            }
        }
    }else if(s == large){
        if(size == large){
            if(abs(rating - r) <= 2){
                return true;
            }
        }
    }
    return false;
}

int Driver::getDistance(Location l){
    return location.getDistance(l);
}

void Driver::print() const{
    if(size == small){
        cout<<"Size: small"<<endl;
    }else if(size == medium){
        cout<<"Size: medium"<<endl;
    }else if(size == large){
        cout<<"Size: large"<<endl;
    }
    
    cout<<"code: "<<code<<endl;
    cout<<"nextId: "<<nextId<<endl;
    User::print();
    cout<<"\n\n"<<endl;
}
