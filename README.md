# Nerd Express.
A ride-hailing program which tries to simulate the backend logic of popular ride-hailing apps, written in C++.

## List of source files:    
 
* Controller.cc: launch() function instantiates and displays a View object to gather user input. This class is used to run tests on the application.   

  
* CoVoiture.cc: This class will maintain multiple data structures. It will store Drivers and Customers and manage their interactions.   

  
* Customer.cc: This class inherits from User   

  
* CustomerList.cc: Maintains a list of customers using a custom data structure   

* defs.h: File which contains preprocessor constants   

  
* Driver.cc: This class inherits from User   

  
* DriverList.cc: Maintains a list of drivers using a custom data structure   

  
* Location.cc: Calculates current location of User object using Manhattan distance   

* main.cc: instantiates a Controller object and calls the launch() function in Controller   

* Makefile: Compiles a single executeable "a3" using the command "make". It also contains a "clean" command which removes the "a3" executeable and any object
           files. This "clean" command is ran using the default "make clean".   
           
  
* User.cc: Defines users (customers & drivers)   

  
* View.cc: Shows a display to gather user input    

* UML_Diagram_Arunteja.png: The UML diagram for this application   


## Directory structure:
None, all files in one directory

## Instructions for compiling code:
Compile using Makefile command "make", which makes the executeable "a3" (in Linux).

## Instructions for running compiled program:
Run the executeable using "./a3".

## Other Notes:
Fyi, the UML diagram (UML_Diagram_Arunteja.png) when opened on windows using Windows Photos could have greyed out boxes if your instance of Windows Photos is in Dark mode.
This issue is fixed if you change Windows Photos to light mode. Another solution is to open the image in Paint or a Web Browser.
