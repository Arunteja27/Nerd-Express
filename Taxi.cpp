#include "Taxi.h"

Taxi::Taxi(int id, const std::pair<int, int>& position)
    : id(id), isAvailable(true), currentPosition(position) {}

void Taxi::pickUpPassenger() {
    isAvailable = false;
}

void Taxi::dropOffPassenger() {
    isAvailable = true;
}
