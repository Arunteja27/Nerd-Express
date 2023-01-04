#include "User.h"

User::User(char c, int i1, const string& s, int i2, Location l):id(string(1,c) + to_string(i1)), name(s), rating(i2), location(l)
{

}

string User::getId() const{
    return id;
}

string User::getName() const{
    return name;
}

Location User::getLocation() const{
    return location;
}

void User::setRating(int r){
    rating = r;
}

void User::setLocation(Location l){
    location = l;
}

void User::setLocation(int x, int y){
    location.x = x;
    location.y = y;
}

void User::print() const{
    cout<<"ID: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Rating: "<<rating<<endl;
    location.print();
}

bool User::lessThan(User u) const{
    return name.compare(u.getName()) < 0;
}

//Check if 2 user's names match/are the same
bool User::matches(const string& n) const{
    return name.compare(n) == 0; 
}

int User::getRating() const{
    return rating;
}