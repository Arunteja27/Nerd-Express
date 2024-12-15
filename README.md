# Nerd Express
A taxi simulation game that mimics the backend logic of ride-hailing apps, written in C++.

## Features
- Interactive taxi simulation through the terminal.
- Implements object-oriented principles with dynamic map updates.
- Calculates taxi movement using Manhattan distance.
- Step-by-step visualization of taxi movements.

## Demo
*A short demo video will be added here soon to showcase the features of Nerd Express.*

## List of Source Files

* **Passenger.h/Passenger.cpp**: Defines the `Passenger` class, which stores and manages passenger information such as pickup and dropoff locations.

* **Taxi.h/Taxi.cpp**: Defines the `Taxi` class, representing individual taxis, their availability, and current positions.

* **Dispatcher.h/Dispatcher.cpp**: Implements the `Dispatcher` class, which manages the game logic, including:
    - Map updates.
    - Taxi assignment based on shortest distance.
    - Handling passenger requests and simulating taxi movements.

* **main.cpp**: The entry point of the application. Initializes the game and provides a menu-driven interface for interacting with the simulation.

* **TerminalRedirect.h/TerminalRedirect.cpp**: Opens GUI in separate terminal window to reduce clutter.

* **Makefile**: Automates compilation and linking of the program. Contains rules for building the project, cleaning object files, and creating the executable.

## Directory Structure
```
.
├── Passenger.h
├── Passenger.cpp
├── Taxi.h
├── Taxi.cpp
├── Dispatcher.h
├── Dispatcher.cpp
├── main.cpp
├── Makefile
```

## Instructions for Compiling the Code
1. Ensure you have `g++` installed (C++17 support is required).
2. Navigate to the project directory in the terminal.
3. Compile the code using the command:

   ```bash
   make
   ```
4. On macOS/Linux, this will generate an executable named `taxi_simulation`. On Windows, it will generate `taxi_simulation.exe`.

## Instructions for Running the Program
1. Run the program by executing:
   - On macOS/Linux:

     ```bash
     ./taxi_simulation
     ```
   - On Windows:

     ```cmd
     taxi_simulation.exe
     ```
2. Follow the menu options to:
   - Request a taxi.
   - View the current map.
   - Exit the simulation.

## Coming Soon!

- More complex features are in development, such as
    - Interactive Open World UX
    - Multiple passenger requests
    - Advanced algorithms for taxi assingments (Dijkstra’s, machine learning demand prediction, Hungarian Algorithm for optimal assignments)

## Other Notes
- The terminal dynamically updates the map during taxi movement.
- The game uses `std::this_thread::sleep_for` to visually display step-by-step taxi movements.
- Feel free to fork and extend this project with additional features!

