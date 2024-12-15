#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <iostream>

class Passenger {
public:
    int id;
    std::string pickupLocation;
    std::string dropoffLocation;

    Passenger(int id, const std::string& pickup, const std::string& dropoff);
    void displayInfo();
};

#endif // PASSENGER_H
