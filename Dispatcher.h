#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "Taxi.h"
#include "Passenger.h"
#include <vector>
#include <unordered_map>
#include <memory>
#include <string>
#include <utility>

class Dispatcher {
    std::vector<std::string> locations;
    std::unordered_map<std::string, std::pair<int, int>> locationMap;
    std::unordered_map<std::string, std::pair<int, int>> locationMapEmote;
    std::unordered_map<std::string, std::string> locationToEmote;
    std::vector<std::vector<std::string>> map;
    std::vector<std::shared_ptr<Taxi>> taxis;
    std::pair<int, int> lastPickup;

public:
    Dispatcher();
    void addTaxi(const std::shared_ptr<Taxi>& taxi);
    void displayMap();
    std::string normalizeInput(const std::string& input);
    int calculateManhattanDistance(const std::pair<int, int>& a, const std::pair<int, int>& b);
    std::shared_ptr<Taxi> findNearestTaxi(const std::pair<int, int>& pickupPos);
    void handleRequest(const std::string& rawPickup, const std::string& rawDropoff);
    void moveTaxi(const std::shared_ptr<Taxi>& taxi, const std::pair<int, int>& start, const std::pair<int, int>& end);
};

#endif // DISPATCHER_H
