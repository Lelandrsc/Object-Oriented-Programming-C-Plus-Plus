#ifndef RPG_H
#define RPG_H

#include <iostream>
#include <string>

using namespace std;

const int SKILL_SIZE = 2;

class RPG {
    public:
        // Constructors
        RPG();
        RPG(string name, int health, int strength, int defense, string type);
        
        // Member functions
        void setSkills();
        void printAction(string action, RPG target);
        void updateHealth(int damage);
        void attack(RPG *target);
        void useSkill(RPG *target);
        bool isAlive() const;
        
        // Getters
        string getName() const;
        int getHealth() const;
        int getStrength() const;
        int getDefense() const;
    
    private:
        string name;
        int health;
        int strength;
        int defense;
        string type; // warrior, mage, thief, archer
        string skills[SKILL_SIZE];
};

// **Missing #endif was added here**
#endif