#include "RPG.h"
#include <iostream>

// Default Constructor
RPG::RPG() {
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills[0] = "slash";
    skills[1] = "parry";
}

// Overloaded Constructor
RPG::RPG(string name, int health, int strength, int defense, string type) {
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
    setSkills();
}

// Accessor Functions
string RPG::getName() const {
    return name;
}

int RPG::getHealth() const {
    return health;
}

int RPG::getStrength() const {
    return strength;
}

int RPG::getDefense() const {
    return defense;
}

/**
 * @brief sets the skills based on the RPG's role
 */
void RPG::setSkills() {
    if (type == "mage") {
        skills[0] = "fire";
        skills[1] = "thunder";
    } else if (type == "thief") {
        skills[0] = "pilfer";
        skills[1] = "jab";
    } else if (type == "archer") {
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    } else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

void RPG::printAction(string skill, RPG opponent) {
    std::cout << name << " used " << skill << " on " << opponent.getName() << std::endl;
}

/**
 * @brief updates health into new_health
 *
 * @param new_health
 */
void RPG::updateHealth(int new_health) {
    health = new_health;
}

/**
 * @brief returns whether health is greater than 0
 *
 * @return true
 * @return false
 */
bool RPG::isAlive() const {
    return health > 0;
}

/**
 * @brief attack decreases the opponent's health by (strength - opponent's defense)
 *
 * @param opponent Pointer to the opponent RPG object
 */
void RPG::attack(RPG* opponent) {
    if (opponent == nullptr) return;  // Safety check

    int damage = strength - opponent->getDefense();
    if (damage < 0) damage = 0;  // Ensure no healing effect

    int new_health = opponent->getHealth() - damage;
    if (new_health < 0) new_health = 0;  // Health should not go negative

    opponent->updateHealth(new_health);

    std::cout << name << " attacks " << opponent->getName() << " for " << damage << " damage!" << std::endl;
}

/**
 * @brief Prompts the user to choose a skill and calls printAction() and attack()
 *
 * @param opponent
 */
void RPG::useSkill(RPG* opponent) {
    if (opponent == nullptr) return;  // Safety check

    // Print out all the player's skills
    for (int i = 0; i < 2; i++) {
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }

    // Prompt user to choose a skill
    int chosen_skill_index;
    std::cout << "Choose a skill to use: Enter 0 or 1\n";
    std::cin >> chosen_skill_index;

    // Validate input
    if (chosen_skill_index < 0 || chosen_skill_index >= 2) {
        std::cout << "Invalid choice. Defaulting to skill 0." << std::endl;
        chosen_skill_index = 0;
    }

    // Assign chosen skill
    std::string chosen_skill = skills[chosen_skill_index];

    // Call printAction and attack
    printAction(chosen_skill, *opponent);
    attack(opponent);
}