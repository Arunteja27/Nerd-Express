
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include "CoVoiture.h"
#include "View.h"

using namespace std;

class Controller {
		
	public:
		
		void launch();

	
	private:
		void initCoVoiture();
		void findRide();
		void removeCustomer();
		void removeDriver();
		
		// these are tutorial tests, here for your convenience
		int findRideTest();
		int customerIdTest();
		int driverIdTest();
		int driverMatchTest();
		const string names[5] = {"Abe","Bae","Cedric","Deb","Elise"};
		const string numbers[5] = {"000","111","222","333","444"};
		
		CoVoiture coVoiture;
		View view;

};
#endif