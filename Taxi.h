#ifndef TAXI_H
#define TAXI_H

#include <utility>

class Taxi {
public:
    int id;
    bool isAvailable;
    std::pair<int, int> currentPosition;

    Taxi(int id, const std::pair<int, int>& position);
    void pickUpPassenger();
    void dropOffPassenger();
};

#endif // TAXI_H
