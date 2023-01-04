#include "Customer.h"

int Customer::nextId = 0;

//Create and return a statically created Location object pointer, for use in the default constructor
Location* Customer::staticLocation() const{
    Location* l;
    return l;
}

Customer::Customer(const string& s):User(code, -1, s, -1, *staticLocation())
{

}


Customer::Customer(const string& name, int rating, Location l):User(code, nextId++, name, rating, l)
{

}

void Customer::print() const{
    cout<<"nextId: "<<nextId<<endl;
    cout<<"code: "<<code<<endl;
    User::print();
    cout<<"\n\n"<<endl;
}