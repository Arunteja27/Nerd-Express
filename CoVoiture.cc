#include "CoVoiture.h"

CoVoiture::CoVoiture(){}

CoVoiture::~CoVoiture(){
   driverList.clear();
   customerList.clear();
}

void CoVoiture::addDriver(const string& name, int rating, Size s, Location l){
    driverList.add(new Driver(name, rating, s, l));
}

bool CoVoiture::getDriver(const string& name, Driver** d) const{
    bool result = driverList.get(name, d);
    if(!result){
        cout<<"Unable to get Driver with name: "<<name<<endl;
    }
    return result;
}

bool CoVoiture::removeDriver(const string& name){
    Driver* driverD;
    bool result = driverList.remove(name, &driverD);
    delete driverD;
    if(!result){
        cout<<"Unable to remove Driver with name: "<<name<<endl;
    }
    return result;
}

void CoVoiture::addCustomer(const string& name, int rating, Location l){
    customerList.add(new Customer(name, rating, l));
}

bool CoVoiture::getCustomer(const string& name, Customer** c) const{
    bool result = customerList.get(name,c);
    if(!result){
        cout<<"Unable to get Customer with name: "<<name<<endl;
    }
    return result;
}

bool CoVoiture::removeCustomer(const string& name){
    Customer* customerC;
    bool result = customerList.remove(name, &customerC);
    delete customerC;
    if(!result){
        cout<<"Unable to remove Customer with name: "<<name<<endl;
    }
    return result;
}

bool CoVoiture::findRide(const string& name, Size size, Driver** d){
    Customer* found;
    if(!getCustomer(name, &found)){
        cout<<"Customer with name "<<name<<" not found"<<endl;
        return false;
    }

    Customer* found2 = found;
    
    if(driverList.findRide(found2->getRating(), size, found2->getLocation(), d)){
        return true;
    }else{
        cout<<"Driver not found for the Customer called "<<name<<endl;
        return false;
    }

}

void CoVoiture::printCustomers() const{
    customerList.print();
}

void CoVoiture::printDrivers() const{
    driverList.print();
}