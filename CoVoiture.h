#ifndef COVOITURE_H
#define COVOITURE_H

#include <iostream>
#include <string>

#include "defs.h"
#include "CustomerList.h"
#include "DriverList.h"


using namespace std;


class CoVoiture{

    public:
        CoVoiture();
        ~CoVoiture();

        //other
        void addDriver(const string&, int, Size, Location);
        bool getDriver(const string&, Driver**) const;
        bool removeDriver(const string&);
        void addCustomer(const string&, int, Location);
        bool getCustomer(const string&, Customer**) const;
        bool removeCustomer(const string&);
        bool findRide(const string&, Size, Driver**);
        void printCustomers() const;
        void printDrivers() const;




    private:
        DriverList driverList;
        CustomerList customerList;

};




#endif