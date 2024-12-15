CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
OBJFILES = main.o Dispatcher.o Taxi.o Passenger.o TerminalRedirect.o
TARGET = taxi_simulation

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES)

main.o: main.cpp Dispatcher.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Dispatcher.o: Dispatcher.cpp Dispatcher.h Taxi.h Passenger.h
	$(CXX) $(CXXFLAGS) -c Dispatcher.cpp

Taxi.o: Taxi.cpp Taxi.h
	$(CXX) $(CXXFLAGS) -c Taxi.cpp

Passenger.o: Passenger.cpp Passenger.h
	$(CXX) $(CXXFLAGS) -c Passenger.cpp

TerminalRedirect.o: TerminalRedirect.cpp TerminalRedirect.h
	$(CXX) $(CXXFLAGS) -c TerminalRedirect.cpp

clean:
	rm -f *.o $(TARGET)
