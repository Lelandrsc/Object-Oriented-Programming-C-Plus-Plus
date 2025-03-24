#include <iostream>
#include "RPG.h"

using namespace std;

void displayStats(RPG player1, RPG player2) {
    cout << player1.getName() << " health: " << player1.getHealth() << " ";
    cout << player2.getName() << " health: " << player2.getHealth() << endl;
}

void gameLoop(RPG* player1, RPG* player2) {
    while (player1->isAlive() && player2->isAlive()) {
        displayStats(*player1, *player2);

        cout << player1->getName() << "'s turn!" << endl;
        player1->useSkill(player2);
        cout << "------------------------------\n";

        if (!player2->isAlive()) break;

        cout << player2->getName() << "'s turn!" << endl;
        player2->useSkill(player1);
        cout << "------------------------------\n";
    }
}

void displayEnd(RPG player1, RPG player2) {
    cout << "Game Over!\n";
    if (player1.isAlive()) {
        cout << player1.getName() << " defeated " << player2.getName() << "! Good game!\n";
    } else {
        cout << player2.getName() << " defeated " << player1.getName() << "! Good game!\n";
    }
}

int main() {
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);

    return 0;
}