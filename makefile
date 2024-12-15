CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
OBJFILES = main.o Passenger.o Taxi.o Dispatcher.o
TARGET = taxi_simulation

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES)

main.o: main.cpp Dispatcher.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Passenger.o: Passenger.cpp Passenger.h
	$(CXX) $(CXXFLAGS) -c Passenger.cpp

Taxi.o: Taxi.cpp Taxi.h
	$(CXX) $(CXXFLAGS) -c Taxi.cpp

Dispatcher.o: Dispatcher.cpp Dispatcher.h Taxi.h Passenger.h
	$(CXX) $(CXXFLAGS) -c Dispatcher.cpp

clean:
	rm -f *.o $(TARGET)
