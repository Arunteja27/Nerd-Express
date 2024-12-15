#include "Dispatcher.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <cmath>
#include <limits>

// Constructor: Initialize the map and location markers
Dispatcher::Dispatcher() : lastPickup{-1, -1} {
    locations = {"Downtown", "Airport", "Mall", "Station", "Hospital"};
    locationMap = {
        {"downtown", {0, 0}}, {"airport", {0, 4}}, {"mall", {2, 0}}, {"station", {2, 4}}, {"hospital", {4, 2}}
    };
   locationMapEmote = {
        {"🏢", {0, 0}}, {"🛩️", {0, 4}}, {"🏪", {2, 0}}, {"🚝", {2, 4}}, {"🏥", {4, 2}}};
   locationToEmote = {
        {"downtown", "🏢"}, {"airport", "🛩️"}, {"mall", "🏪"}, {"station", "🚝"}, {"hospital", "🏥"}};
    map.resize(5, std::vector<std::string>(5, "⚪️"));
    for (const auto& loc : locationMapEmote) {
        map[loc.second.first][loc.second.second] = loc.first;
    }
}

// Add a taxi to the dispatcher and update its initial position on the map
void Dispatcher::addTaxi(const std::shared_ptr<Taxi>& taxi) {
    taxis.push_back(taxi);
    map[taxi->currentPosition.first][taxi->currentPosition.second] = "🚕";
}

// Display the map
void Dispatcher::displayMap() {
    std::cout << "\nCity Map:\n";
    for (const auto& row : map) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

// Normalize user input to lowercase
std::string Dispatcher::normalizeInput(const std::string& input) {
    std::string normalized = input;
    std::transform(normalized.begin(), normalized.end(), normalized.begin(), ::tolower);
    return normalized;
}

// Calculate Manhattan distance between two points
int Dispatcher::calculateManhattanDistance(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

// Find the nearest available taxi
std::shared_ptr<Taxi> Dispatcher::findNearestTaxi(const std::pair<int, int>& pickupPos) {
    std::shared_ptr<Taxi> nearestTaxi = nullptr;
    int minDistance = std::numeric_limits<int>::max();

    for (const auto& taxi : taxis) {
        if (taxi->isAvailable) {
            int distance = calculateManhattanDistance(taxi->currentPosition, pickupPos);
            if (distance < minDistance) {
                minDistance = distance;
                nearestTaxi = taxi;
            }
        }
    }
    return nearestTaxi;
}

// Handle a passenger request
void Dispatcher::handleRequest(const std::string& rawPickup, const std::string& rawDropoff) {
    std::string pickup = normalizeInput(rawPickup);
    std::string dropoff = normalizeInput(rawDropoff);

    if (locationMap.find(pickup) == locationMap.end() || locationMap.find(dropoff) == locationMap.end()) {
        std::cout << "Invalid location(s) entered. Please try again.\n";
        return;
    }

    auto pickupPos = locationMap[pickup];
    auto dropoffPos = locationMap[dropoff];

    // Find the nearest available taxi
    auto taxi = findNearestTaxi(pickupPos);
    if (!taxi) {
        std::cout << "No taxis available.\n";
        return;
    }

    // Clear the taxi's previous position
    map[taxi->currentPosition.first][taxi->currentPosition.second] = taxi->currentPosition.second;

    auto start = taxi->currentPosition;

    // Restore the previous pickup point marker
    if (lastPickup.first != -1 && lastPickup.second != -1) {
        for (const auto& loc : locationMapEmote) {
            if (loc.second == lastPickup) {
                map[lastPickup.first][lastPickup.second] = loc.first;
                break;
            }
        }
    }

    // Update last pickup point
    lastPickup = pickupPos;

    // Replace the pickup point with "🏠"
    map[pickupPos.first][pickupPos.second] = "🏠";

    // Move to pickup location
    moveTaxi(taxi, start, pickupPos);
    std::cout << "Taxi " << taxi->id << " picked up a passenger at " << rawPickup << ".\n";
    taxi->pickUpPassenger();

    // Move to dropoff location
    moveTaxi(taxi, pickupPos, dropoffPos);
    std::cout << "Taxi " << taxi->id << " dropped off the passenger at " << rawDropoff << ".\n";
    taxi->dropOffPassenger();

    // Restore dropoff location marker
    for (const auto& loc : locationMapEmote) {
        if (loc.second == dropoffPos) {
            map[dropoffPos.first][dropoffPos.second] = loc.first;
            break;
        }
    }

    // Clear the "🏠" marker after the trip ends
    map[pickupPos.first][pickupPos.second] = locationToEmote[pickup];

    // Update taxi's current position
    taxi->currentPosition = dropoffPos;
    map[taxi->currentPosition.first][taxi->currentPosition.second] = "🚕";
}

// Move the taxi step by step to the destination
void Dispatcher::moveTaxi(const std::shared_ptr<Taxi>& taxi, const std::pair<int, int>& start, const std::pair<int, int>& end) {
        auto [x1, y1] = start;
        auto [x2, y2] = end;

        // Save the original marker of the starting location
        std::string originalMarker = map[x1][y1];

        // Clear taxi's current position on the map
        map[x1][y1] = originalMarker;

        // Move horizontally
        while (x1 != x2) {
            x1 += (x2 > x1) ? 1 : -1;
            std::string tempMarker = map[x1][y1];
            map[x1][y1] = "🚕";
            displayMap();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            map[x1][y1] = tempMarker;
        }

        // Move vertically
        while (y1 != y2) {
            y1 += (y2 > y1) ? 1 : -1;
            std::string tempMarker = map[x1][y1];
            map[x1][y1] = "🚕";
            displayMap();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            map[x1][y1] = tempMarker;
        }
}
