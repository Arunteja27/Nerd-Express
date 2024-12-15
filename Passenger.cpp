#include "Passenger.h"

Passenger::Passenger(int id, const std::string& pickup, const std::string& dropoff)
    : id(id), pickupLocation(pickup), dropoffLocation(dropoff) {}

void Passenger::displayInfo() {
    std::cout << "Passenger " << id << ": from " << pickupLocation
              << " to " << dropoffLocation << "\n";
}
