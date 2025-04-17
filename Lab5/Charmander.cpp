#include <iostream>
#include <vector>
#include <string>
#include "Charmander.h"

using namespace std;

/**
 * @brief Construct a new Charmander::Charmander object (default)
 */
Charmander::Charmander() : Pokemon() {
    type.push_back("Fire");
    skills.push_back("Growl");
    skills.push_back("Scratch");

    cout << "Default Constructor (Charmander)\n";
}

/**
 * @brief Construct a new Charmander::Charmander object (overloaded)
 * 
 * @param name  Name of the Pokemon
 * @param hp    Hit Points
 * @param att   Attack value
 * @param def   Defense value
 * @param t     Type vector
 * @param s     Skills vector
 */
Charmander::Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s)
    : Pokemon(name, hp, att, def, t) {
    type = t;
    skills = s;
    cout << "Overloaded Constructor (Charmander)\n";
}

/**
 * @brief Charmander speaks
 */
void Charmander::speak() {
    cout << "Charmander-char\n";
}

/**
 * @brief Calls printStats from the parent class and adds Charmander's skills
 */
void Charmander::printStats() {
    Pokemon::printStats();
    cout << "Skills: ";
    for (int i = 0; i < skills.size(); i++) {
        cout << skills[i] << "\t";
    }
    cout << endl;
}
