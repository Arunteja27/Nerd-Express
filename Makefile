objects = main.o Controller.o View.o CoVoiture.o User.o CustomerList.o DriverList.o  Driver.o Customer.o Location.o

a3: $(objects)
	g++ -o a3 $(objects) 

main.o: main.cc Controller.h 
	g++ -c main.cc 

Controller.o: Controller.h Controller.cc
	g++ -c Controller.cc
	
View.o: View.cc View.h
	g++ -c View.cc
	
CoVoiture.o: CoVoiture.cc CoVoiture.h
	g++ -c CoVoiture.cc

User.o: User.cc User.h
	g++ -c User.cc

DriverList.o: DriverList.h DriverList.cc
	g++ -c DriverList.cc

CustomerList.o: CustomerList.h CustomerList.cc
	g++ -c CustomerList.cc
	
Driver.o: Driver.cc Driver.h User.h
	g++ -c Driver.cc 

Customer.o: Customer.cc Customer.h 
	g++ -c Customer.cc

Location.o: Location.cc Location.h
	g++ -c Location.cc
	

clean:
	rm -f a3 *.o