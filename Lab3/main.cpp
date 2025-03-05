#include <iostream>
#include "RPG.h"

using namespace std;

int main() {
    // Creating RPG objects
    RPG defaultRPG; // Uses default constructor
    RPG customRPG("Hero", 120, 15, 12, "mage"); // Uses overloaded constructor

    // Testing accessor functions
    cout << "Default RPG Name: " << defaultRPG.getName() << endl;
    cout << "Custom RPG Name: " << customRPG.getName() << endl;
    cout << "Custom RPG Health: " << customRPG.getHealth() << endl;
    
    // Testing isAlive function
    cout << "Is Default RPG Alive? " << (defaultRPG.isAlive() ? "Yes" : "No") << endl;
    cout << "Is Custom RPG Alive? " << (customRPG.isAlive() ? "Yes" : "No") << endl;

    // Testing updateHealth function
    cout << "Updating Default RPG health to 0..." << endl;
    defaultRPG.updateHealth(0);
    cout << "Is Default RPG Alive? " << (defaultRPG.isAlive() ? "Yes" : "No") << endl;

    return 0;
}
