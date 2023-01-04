
#include "Controller.h"
#include <sstream>

#define ARR 5

void Controller::launch(){
    initCoVoiture();

    int choice = -1;

    while(choice!=0){
        view.displayMenu(choice);
        switch(choice){
            case 1: coVoiture.printDrivers(); break;
            case 2: coVoiture.printCustomers(); break;
            case 3: findRide(); break;
            case 4: removeDriver(); break;
            case 5: removeCustomer(); break;
            case 6: cout<< (customerIdTest()==0?"Successful test":"Failure")<<endl; break;
		    case 7: cout<< (driverIdTest()==0?"Successful test":"Failure")<<endl; break;
		    case 8: cout<< (driverMatchTest()==0?"Successful test":"Failure")<<endl; break;
            case 9: cout<< (findRideTest()==0?"Successful test":"Failure")<<endl; break;
        }
    }

    cout<<"Bye!"<<endl;

    
}




void Controller::initCoVoiture(){
    
    coVoiture.addDriver("Elsa", 5, medium, Location(3,4));
    coVoiture.addDriver("Densel", 4, small, Location(1,1));
    coVoiture.addDriver("Carter", 3, large, Location(5,4));
    coVoiture.addDriver("Bob", 4, small, Location(2, 2));
    coVoiture.addDriver("Alice", 5, medium, Location(7, 7));

    coVoiture.addCustomer("Sally", 2, Location(5, 5));
    coVoiture.addCustomer("Jesse", 5, Location(3, 7));
    coVoiture.addCustomer("Isabelle", 4, Location(4, 5));
    coVoiture.addCustomer("Philip", 3, Location(1, 7));

}

void Controller::findRide(){
    string name;
    Size size;
    view.getRideInfo(name, size);
    coVoiture.printDrivers();

    Driver* d;
    if (coVoiture.findRide(name, size, &d)){
        cout<<"Driver found for "<<name<<"!"<<endl;
        d->print();
    }else{
        cout<<"No match found, try again later"<<endl;
    }

    
}

void Controller::removeCustomer(){
  string name;
  view.getName(name);
  if (!coVoiture.removeCustomer(name)){
    cout<<name<<" not found"<<endl;
  }
}

void Controller::removeDriver(){
  string name;
  view.getName(name);
  if (!coVoiture.removeDriver(name)){
    cout<<name<<" not found"<<endl;
  }
}

int Controller::findRideTest(){
  DriverList drivers;
  // changed to object array to avoid memory leaks
  Driver ds[ARR] = { Driver("Elsa", 5, medium, Location(3,4)), Driver("Densel", 4, small, Location(1,1)), Driver("Carter", 2, large, Location(5,4)), Driver("Bob", 4, small, Location(2, 2)), Driver("Alice", 5, medium, Location(7, 7)) };
  drivers.add(&ds[0]);
  drivers.add(&ds[1]);
  drivers.add(&ds[2]);
  drivers.add(&ds[3]);
  drivers.add(&ds[4]);

  Driver* d;
  if (drivers.findRide(2, large, Location(1,1), &d)){
    if (d == &ds[2]){
      cout << "Correct driver found!"<<endl;
      d->print();
    }else{
      cout << "Test failed, wrong driver found! Only Carter has a large vehicle."<<endl;
      d->print();
      return 1;
    }
  }else{
    cout << "Test failed, no driver found! (Should find Carter.)"<<endl;
    return 1;
  }

  if (drivers.findRide(5, small, Location(4,4), &d)){
    if (d == &ds[0]){
      cout << "Correct driver found!"<<endl;
      d->print();
    }else{
      cout << "Test failed, wrong driver found! Elsa is closest."<<endl;
      d->print();
      return 1;
    }
  }else{
    cout << "Test failed, no driver found! (Should find Elsa.)"<<endl;
    return 1;
  }

  if (drivers.findRide(4, small, Location(6,6), &d)){
    if (d == &ds[4]){
      cout << "Correct driver found!"<<endl;
      d->print();
    }else{
      cout << "Test failed, wrong driver found! Alice is closest."<<endl;
      d->print();
      return 1;
    }
  }else{
    cout << "Test failed, no driver found! (Should find Alice.)"<<endl;
    return 1;
  }


  if (drivers.findRide(5, large, Location(6,6), &d)){
      cout << "Test failed, driver found but none matched the criteria."<<endl;
      d->print();
      return 1;
  }else{
    cout << "Test succeeded, no driver found! "<<endl;
  }

  return 0;
  

}

int Controller::customerIdTest(){
    int nums[ARR] = {4,0,1,3,2};
    string strs[ARR] = {"C5","C1","C2","C4", "C3"}; 
    // changed to object array to avoid memory leaks
    Customer customers[ARR] = { Customer(names[0]), Customer(names[1]), Customer(names[2]), Customer(names[3]), Customer(names[4]) };

    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    

    //reset stringstream
    for (int i = 0; i < ARR; ++i){
        //move std::cout to an ostringstream
        std::cout.rdbuf( strCout.rdbuf() );
        customers[nums[i]].print();
        //replace the old std::cout
        std::cout.rdbuf( oldCoutStreamBuf );
        //grab the output and write it to the console
        string output = strCout.str();
        std::cout << output;
        //reset the stream
        strCout.str(std::string());
        //search the output
        if (output.find(strs[i])){
          cout << strs[i]<<" found, success!"<<endl;
        }else{
          cout << strs[i]<<" not found, test failed!"<<endl;
          return 1;
        }
    }

    return 0;
}

// make some drivers and check their id number
int Controller::driverIdTest(){
    int nums[ARR] = {4,0,1,3,2};
    string strs[ARR] = {"D5","D1","D2","D4", "D3"}; 
    // changed to object array to avoid memory leaks
    Driver drivers[ARR] = { Driver(names[0]), Driver(names[1]), Driver(names[2]), Driver(names[3]), Driver(names[4]) };;

    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    

    //reset stringstream
    for (int i = 0; i < ARR; ++i){
        //move std::cout to an ostringstream
        std::cout.rdbuf( strCout.rdbuf() );
        drivers[nums[i]].print();
        //replace the old std::cout
        std::cout.rdbuf( oldCoutStreamBuf );
        //grab the output and write it to the console
        string output = strCout.str();
        std::cout << output;
        //reset the stream
        strCout.str(std::string());
        //search the output
        if (output.find(strs[i])){
          cout << strs[i]<<" found, success!"<<endl;
        }else{
          cout << strs[i]<<" not found, test failed!"<<endl;
          return 1;
        }
    }

    return 0;
}

int Controller::driverMatchTest(){
  // changed to object array to avoid memory leaks
  Driver ds[ARR] = { Driver("Elsa", 5, medium, Location(3,4)), Driver("Densel", 4, small, Location(1,1)), Driver("Carter", 2, large, Location(5,4)), Driver("Bob", 4, small, Location(2, 2)), Driver("Alice", 5, medium, Location(7, 7)) };

  cout<<"Testing match (5, medium) to (5 medium)..."<<endl;
  if (ds[0].match(5, medium)){
    cout<<"Match successful, test passed!"<<endl;
  }else{
    cout<<"Match not successful, test failed!"<<endl;
    return 1;
  }

  cout<<"Testing match (3, medium) to (5 medium)..."<<endl;
  if (ds[0].match(3, medium)){
    cout<<"Match successful, test passed!"<<endl;
  }else{
    cout<<"Match not successful, test failed!"<<endl;
    return 1;
  }

  cout<<"Testing match (2, medium) to (5 medium)..."<<endl;
  if (ds[0].match(2, medium)){
    cout<<"Match successful, test failed!"<<endl;
    return 1;
  }else{
    cout<<"Match not successful, test passed!"<<endl;
  }

  cout<<"Testing match (2, large) to (2 large)..."<<endl;
  if (ds[2].match(2, large)){
    cout<<"Match successful, test passed!"<<endl;
  }else{
    cout<<"Match not successful, test failed!"<<endl;
    return 1;
  }

  cout<<"Testing match (5, large) to (2 large)..."<<endl;
  if (ds[2].match(5, large)){
    cout<<"Match successful, test failed!"<<endl;
    return 1;
  }else{
    cout<<"Match not successful, test passed!"<<endl;
  }

  cout<<"Testing match (2, small) to (2 large)..."<<endl;
  if (ds[2].match(2, small)){
    cout<<"Match successful, test passed!"<<endl;
  }else{
    cout<<"Match not successful, test failed!"<<endl;
    return 1;
  }

  cout<<"Testing match (3, medium) to (4, small)..."<<endl;
  if (ds[3].match(3, medium)){
    cout<<"Match successful, test failed!"<<endl;
    return 1;
  }else{
    cout<<"Match not successful, test passed!"<<endl;
  }

  cout<<"Testing match (5, large) to (5, medium)..."<<endl;
  if (ds[4].match(5, large)){
    cout<<"Match successful, test failed!"<<endl;
    return 1;
  }else{
    cout<<"Match not successful, test passed!"<<endl;
  }

  // all tests passed
  return 0;
}
