# Ride_Hailing_Program
A ride-hailing program which tries to simulate the logic of popular ride-hailing apps.

List of source files:
Controller.h
Controller.cc: launch() function instantiates and displays a View object to gather user input. This class is used to run tests on the application.
CoVoiture.h
CoVoiture.cc: This class will maintain multiple data structures. It will store Drivers and Customers and manage their interactions.
Customer.h
Customer.cc: This class inherits from User
CustomerList.h
CustomerList.cc: Maintains a list of customers using a custom data structure
defs.h: File which contains preprocessor constants
Driver.h
Driver.cc: This class inherits from User
DriverList.h
DriverList.cc: Maintains a list of drivers using a custom data structure
Location.h
Location.cc: Calculates current location of User object using Manhattan distance
main.cc: instantiates a Controller object and calls the launch() function in Controller
Makefile: Compiles a single executeable "a3" using the command "make". It also contains a "clean" command which removes the "a3" executeable and any object
           files. This "clean" command is ran using the default "make clean".
User.h
User.cc: Defines users (customers & drivers)
View.h
View.cc: Shows a display to gather user input
UML_Diagram_Arunteja.png: The UML diagram for this application


Directory structure:
None, all files in one directory

Instructions for compiling code:
Compile using Makefile command "make", which makes the executeable "a3" (in Linux).

Instructions for running compiled program:
Run the executeable using "./a3".

Other Notes:
Fyi, the UML diagram (UML_Diagram_Arunteja.png) when opened on windows using Windows Photos could have greyed out boxes if your instance of Windows Photos is in Dark mode.
This issue is fixed if you change Windows Photos to light mode. Another solution is to open the image in Paint or a Web Browser.
