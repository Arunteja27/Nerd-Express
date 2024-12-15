#include "Dispatcher.h"
#include <iostream>

int main() {
    Dispatcher dispatcher;

    // Add taxis to the dispatcher
    for (int i = 1; i <= 3; ++i) {
        dispatcher.addTaxi(std::make_shared<Taxi>(i, std::make_pair(0, 0)));
    }

    int choice;
    do {
        std::cout << "\nTaxi Simulation Game\n";
        std::cout << "1. Request a Taxi\n";
        std::cout << "2. View Map\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string pickup, dropoff;
            std::cout << "Enter pickup location: ";
            std::cin >> pickup;
            std::cout << "Enter dropoff location: ";
            std::cin >> dropoff;
            dispatcher.handleRequest(pickup, dropoff);
        } else if (choice == 2) {
            dispatcher.displayMap();
        } else if (choice != 3) {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    std::cout << "Thank you for playing!\n";

    return 0;
}
