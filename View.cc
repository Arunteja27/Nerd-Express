
#include "View.h"
#include <sstream>
#include "Driver.h"
#include "Customer.h"

using namespace std;


void View::displayMenu(int& choice){
    int numOptions = 9;

    cout << endl;
    cout << "What would you like to do?"<< endl;
    cout << "  (1) Print all drivers" << endl;
    cout << "  (2) Print all customers" << endl;
    cout << "  (3) Take a ride" << endl;
    cout << "  (4) Remove a driver" << endl;
    cout << "  (5) Remove a customer" << endl;
    cout << endl<<"Tests (from the tutorials, for convenience):"<<endl;
    cout << "  (6) Customer id test" << endl;
    cout << "  (7) Driver id test" << endl;
    cout << "  (8) Driver match test" << endl;
    cout << "  (9) Find ride test" << endl<<endl;
    cout << "  (0) Exit" << endl<<endl;

    cout << "Enter your selection: ";
    cin >> choice;
    if (choice == 0)
        return;

    while (choice < 0 || choice > numOptions) {
        cout << "Enter your selection: ";
        cin >> choice;
    }
}

void View::getRideInfo(string& name, Size& size){
    cout<<"Enter customer name: ";
    cin >> name;
    cout << endl;
    cout<<"What size of car do you need?"<<endl;
    cout<<"(1) Small"<<endl;
    cout<<"(2) Medium"<<endl;
    cout<<"(3) Large"<<endl;
    int s = 0;
    cin>>s;
    size = (Size)(s-1);
}

void View::getName(string& name){
    cout<<"Enter goner's name: ";
    cin >> name;
    cout << endl;
}



