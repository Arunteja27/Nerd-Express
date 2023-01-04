
#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <sstream>
#include "defs.h"

using namespace std;

class View {
		
	public:	
		void displayMenu(int& choice);
		void getName(string& name);
		void getRideInfo(string& custName, Size& size);
};
#endif