#include <iostream>
#include <string>

using namespace std;

#include "Charm.h"
#include "Equipment.h"

const int MAX_CHARMS = 5;

void printIntro() {
    cout << "—HK CHARM SIMULATOR—" << endl;
    cout << R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠶⠀⠀⠀⠀⠀⣈⣿⣦⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠹⣿⣿⡆⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣤⣤⣴⣤⣤⣄⠀⢠⣿⣿⠇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣾⠋⠈⢻⣿⡝⠁⠀⢻⣿⣿⠋⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠈⣿⣄⣠⣿⣿⣧⣀⣠⣿⣿⣿⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⡿⠟⠀⣀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣷⡾⠿⠛⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⡿⠓⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣀⡀⠀⠀⠀⠀⠀
⠀⣰⡟⠉⣼⣿⠟⣡⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⡀⠀
⢠⣿⠀⠀⣿⣿⣾⠿⠛⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡛⠻⠑⡀
⠈⣿⠀⡼⢿⡏⠀⠀⠀⠹⣿⡆⠉⠻⣿⣿⣿⣿⣿⡻⢿⣿⠷⠞⠁
⠀⢸⠇⠀⠈⡇⠀⠀⠀⠀⠘⢿⡄⠀⠸⡏⠀⠀⠉⡇⠀⠹⢦⡄⠀
⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠸⠁⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀)";
    cout << "\nHere you may rest and change out your charms." << endl;
}

void printCommands() {
    cout << "-----------------------------------------" << endl;
    cout << "Commands:" << endl;
    cout << "add [name]: Equip a charm." << endl;
    cout << "rm [name]: Unequip a charm." << endl;
    cout << "info [name]: See charm description." << endl;
    cout << "\nview: See filled notches." << endl;
    cout << "incr [#]: Add extra notches." << endl;
    cout << "list eq: Show equipped charms." << endl;
    cout << "list all: Show all charms." << endl;
    cout << "\nhelp: Display commands." << endl;
    cout << "quit: Quit program." << endl;
    cout << "-----------------------------------------" << endl;
}

// Use a linear search to find a charm with a specific name
int searchCharms(Charm charmList[], int size, string name) {
    for (int i = 0; i < size; i++) {
        if (charmList[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

int main() {
    string command;
    string name;
    string clarifier;
    int index;
    int incr;

    Equipment inventory;

    Charm allCharms[MAX_CHARMS];

    Charm charm1("Wayward Compass", "Whispers its location to the bearer whenever a map is open, allowing wanderers to pinpoint their current location.", 1);
    Charm charm2("Gathering Swarm", "A swarm will follow the bearer and gather up any loose Geo. Useful for those who can't bear to leave anything behind, no matter how insignificant.", 1);
    Charm charm3("Stalwart Shell", "Builds resilience. When recovering from damage, the bearer will remain invulnerable for longer. Makes it easier to escape from dangerous situations.", 2);
    Charm charm4("Soul Catcher", "Used by shamans to draw more SOUL from the world around them. Increases the amount of SOUL gained when striking an enemy with the nail.", 2);
    Charm charm5("Shaman Stone", "Said to contain the knowledge of past generations of shaman. Increases the power of spells, dealing more damage to foes.", 3);

    allCharms[0] = charm1;
    allCharms[1] = charm2;
    allCharms[2] = charm3;
    allCharms[3] = charm4;
    allCharms[4] = charm5;

    printIntro();
    printCommands();

    cout << endl;
    cin >> command;

    while (command != "quit") {
        if (command == "add") {
            cin >> ws;
            getline(cin, name);
            index = searchCharms(allCharms, MAX_CHARMS, name);

            if (index == -1) {
                cout << ">" << name << " does not exist." << endl;
            } else {
                Charm chosenCharm = allCharms[index];

                if (inventory.equipCharm(chosenCharm)) {
                    cout << ">Successfully equipped " << chosenCharm.getName() << "." << endl;
                }
            }

        } 
        else if (command == "rm") {
            cin >> ws;
            getline(cin, name);
            index = searchCharms(allCharms, MAX_CHARMS, name);

            if (index == -1) {
                cout << ">" << name << " does not exist." << endl;
            } else {
                Charm chosenCharm = allCharms[index];

                if (inventory.removeCharm(chosenCharm)) {
                    cout << ">Successfully removed " << chosenCharm.getName() << "." << endl;
                } else {
                    cout << ">" << chosenCharm.getName() << " is not equipped." << endl;
                }
            }
        }  
        else if (command == "info") {
            cin >> ws;
            getline(cin, name);
            index = searchCharms(allCharms, MAX_CHARMS, name);

            if (index == -1) {
                cout << ">" << name << " does not exist." << endl;
            } else {
                Charm chosenCharm = allCharms[index];
                cout << ">" << "Entry:\n";
                cout << chosenCharm.getInfoWithDesc() << endl;
            }
        }
        else if (command == "view") {
            cout << ">Notches:" << endl;
            cout << inventory.getNotchInfo() << endl;
        }
        else if (command == "incr") {
            cin >> incr;

            if (incr > 0) {
                inventory.setMaxNotches(inventory.getMaxNotches() + incr);
                if (incr == 1) {
                    cout << ">Added " << incr << " notch. Total is now " << inventory.getUsedNotches() << "/" << inventory.getMaxNotches() << "." << endl;
                } else {
                    cout << ">Added " << incr << " notches. Total is now " << inventory.getUsedNotches() << "/" << inventory.getMaxNotches() << "." << endl;
                }
            } else {
                cout << ">Invalid value. Please enter a positive integer." << endl;
            }

        }
        else if (command == "list") {
            cin >> clarifier;

            // Equipped
            if (clarifier == "eq") {
                cout << inventory.getCharmInfo() << endl;
            }

            // All
            if (clarifier == "all") {
                cout << ">All Charms:" << endl;
                for (int i = 0; i < MAX_CHARMS; i++) {
                    cout << allCharms[i].getInfo() << endl;
                }
            }

        }
        else if (command == "help") {
            printCommands();
        } 
        else {
            cout << ">Command not recognized. Type 'help' for a list of commands." << endl;
        }

        cout << endl;
        cin >> command;
    }

    cout << ">Quitting program.";
    return 0;
}

