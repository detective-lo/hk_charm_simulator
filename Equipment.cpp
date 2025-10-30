#include <iostream>

using namespace std;

#include "Equipment.h"

Equipment::Equipment() {
    maxNotches = 3;
    usedNotches = 0;
    maxCharms = 10;
    usedCharms = 0;
    charms = new Charm[10];
    overcharmed = false;
}

Equipment::Equipment(int maxNotches) {
    this->maxNotches = maxNotches;
    usedNotches = 0;
    maxCharms = 10;
    usedCharms = 0;
    charms = new Charm[10];
    overcharmed = false;
}

Equipment::~Equipment() {
    delete[] charms;
}

Equipment::Equipment(const Equipment& other) {
    maxNotches = other.maxNotches;
    usedNotches = other.usedNotches;
    maxCharms = other.maxCharms;
    usedCharms = other.usedCharms;

    charms = new Charm[maxCharms];
    for (int i = 0; i < maxCharms; i++) {
        charms[i] = other.charms[i];
    }

    overcharmed = false;
}

int Equipment::getMaxNotches() const {
    return maxNotches;
}

void Equipment::setMaxNotches(int maxNotches) {
    this->maxNotches = maxNotches;
}

int Equipment::getUsedNotches() const {
    return usedNotches;
}

void Equipment::setUsedNotches(int usedNotches) {
    this->usedNotches = usedNotches;
}

int Equipment::getMaxCharms() const {
    return maxCharms;
}

void Equipment::setMaxCharms(int maxCharms) {
    this->maxCharms = maxCharms;
}

int Equipment::getUsedCharms() const {
    return usedCharms;
}

void Equipment::setUsedCharms(int usedCharms) {
    this->usedCharms = usedCharms;
}

bool Equipment::equipCharm(Charm chosenCharm) {
    // Check if charm slots are full
    if ((usedCharms+1) == maxCharms) {
        cout << ">Charm slots are full." << endl;
        return false;
    }

    // Check if charm is already equipped
    for (int i = 0; i < usedCharms; i++) {
        if (charms[i].getName() == chosenCharm.getName()) {
            cout << ">" << chosenCharm.getName() << " is already equipped." << endl;
            return false;
        }
    }

    // Allow overcharming
    if ((usedNotches + chosenCharm.getNotches()) > maxNotches) {
        if (overcharmed) {
            cout << ">You are already Overcharmed. Please remove a charm." << endl;
            return false;
        } 
        flipOvercharmed();
        cout << ">WARNING: You are now Overcharmed." << endl;
    }

    charms[usedCharms] = chosenCharm;
    usedCharms++;
    usedNotches += chosenCharm.getNotches();

    return true; // successfully equipped charm
}

bool Equipment::removeCharm(Charm chosenCharm) {
    Charm *newCharms = new Charm[maxCharms];
    bool found = false;

    for (int i = 0; i < usedCharms; i++) {
        if (charms[i].getName() == chosenCharm.getName()) {
            found = true;
            usedNotches -= charms[i].getNotches();
            usedCharms--;

            for (int j = i; j < usedCharms-1 ; j++) {
                newCharms[j] = charms[j+1];;
            }

            // No longer overcharmed if notches drop below max
            if (overcharmed && usedNotches <= maxNotches) {
                flipOvercharmed();
            }

            return true; // charm was found and removed

        } else {
            newCharms[i] = charms[i];
        }
    }

    return false; // charm not found
}

void Equipment::incrNotches(int incr) {
    maxNotches += incr;
}

void Equipment::incrCharms(int incr) {
    if (incr <= 0) {
        return;
    }

    Charm *newCharms = new Charm[maxCharms + incr];

    for (int i = 0; i < maxCharms; i++) {
        newCharms[i] = charms[i];
    }

    delete[] charms;
    charms = newCharms;
    maxCharms += incr;
}

string Equipment::getCharmInfo() const {
    string info = "";

    if (usedCharms == 0) {
        info += ">No charms equipped.";
        return info;
    } 

    info += ">Equipped Charms:\n";
    for (int i = 0; i < usedCharms; i++) {
        if (i == usedCharms-1) {
            info += charms[i].getInfo();
        } else {
            info += charms[i].getInfo() + "\n";
        } 
    }

    return info;
}

string Equipment::getNotchInfo() const {
    string display = "";

    for (int i = 0; i < maxNotches; i++) {
        display += "[";

        if (usedNotches > i) {
            display += "X";
        } else {
            display += "O";
        }

        display += "]";
    }

    // Only for overcharming
    if (overcharmed) {
        display += "---";
        for (int j = maxNotches; j < usedNotches; j++) {
            display += "[";
            display += "X";
            display += "]";
        }
        display += "\nOVERCHARMED";
    }

    return display;
}

bool Equipment::getOvercharmed() const {
    return overcharmed;
}

void Equipment::flipOvercharmed() {
    overcharmed = !overcharmed;
}