#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "Charm.h"
#include "Equipment.h"

const int MAX_CHARMS = 40;

void printIntro() {
    cout << "\n-HOLLOW KNIGHT CHARM SIMULATOR-";
    cout << "\nHere you may rest and change out your charms.\n" << endl;
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

void setupCharmList(Charm allCharms[]) {
    Charm charm1("Wayward Compass", "Whispers its location to the bearer whenever a map is open, allowing wanderers to pinpoint their current location.", 1);
    Charm charm2("Gathering Swarm", "A swarm will follow the bearer and gather up any loose Geo. Useful for those who can't bear to leave anything behind, no matter how insignificant.", 1);
    Charm charm3("Stalwart Shell", "Builds resilience. When recovering from damage, the bearer will remain invulnerable for longer. Makes it easier to escape from dangerous situations.", 2);
    Charm charm4("Soul Catcher", "Used by shamans to draw more SOUL from the world around them. Increases the amount of SOUL gained when striking an enemy with the nail.", 2);
    Charm charm5("Shaman Stone", "Said to contain the knowledge of past generations of shaman. Increases the power of spells, dealing more damage to foes.", 3);
    Charm charm6("Soul Eater", "Forgotten shaman artifact, used to draw SOUL from still-living creatures. Greatly increases the amount of SOUL gained when striking an enemy with the nail.", 4);
    Charm charm7("Dashmaster", "Bears the likeness of an eccentric bug known only as 'The Dashmaster'. The bearer will be able to dash more often as well as dash downwards. Perfect for those who want to move around as quickly as possible.", 2);
    Charm charm8("Sprintmaster", "Bears the likeness of a strange bug known only as 'The Sprintmaster'. Increases the running speed of the bearer, allowing them to avoid danger or overtake rivals.", 1);
    Charm charm9("Grubsong", "Contains the gratitude of freed grubs. Gain SOUL when taking damage.", 1);
    Charm charm10("Grubberfly's Elegy", "Contains the gratitude of grubs who will move to the next stage of their lives. Imbues weapons with a holy strength. When the bearer is at full health, they will fire beams of white-hot energy from their nail.", 3);
    Charm charm11("Unbreakable Heart", "Increases the health of the bearer, allowing them to take more damage. This charm is unbreakable.", 2);
    Charm charm12("Unbreakable Greed", "Causes the bearer to find more Geo when defeating enemies. This charm is unbreakable.", 2);
    Charm charm13("Unbreakable Strength", "Strengthens the bearer, increasing the damage they deal to enemies with their nail. This charm is unbreakable.", 3);
    Charm charm14("Spell Twister", "Reflecting the desires of the Soul Sanctum for mastery over SOUL, it improves the bearer's ability to cast spells. Reduces the SOUL cost of casting spells.", 2);
    Charm charm15("Steady Body", "Keeps its bearer from recoiling backwards when they strike an enemy with a nail. Allows one to stay steady and keep attacking.", 1);
    Charm charm16("Heavy Blow", "Formed from the nails of fallen warriors. Increases the force of the bearer's nail, causing enemies to recoil further when hit.", 2);
    Charm charm17("Quick Slash", "Born from imperfect, discarded nails that have fused together. The nails still long to be wielded. Allows the bearer to slash much more rapidly with their nail.", 3);
    Charm charm18("Longnail", "Increases the range of the bearer's nail, allowing them to strike foes from further away.", 2);
    Charm charm19("Mark of Pride", "Freely given by the Mantis Tribe to those they respect. Greatly increases the range of the bearer's nail, allowing them to strike foes from further away.", 3);
    Charm charm20("Fury of the Fallen", "Embodies the fury and heroism that comes upon those who are about to die. When close to death, the bearer's strength will increase.", 2);
    Charm charm21("Thorns of Agony", "Senses the pain of its bearer and lashes out at the world around them. When taking damage, sprout thorny vines that damage nearby foes.", 1);
    Charm charm22("Baldur Shell", "Protects its bearer with a hard shell while focusing SOUL. The shell is not indestructible and will shatter if it absorbs too much damage.", 2);
    Charm charm23("Flukenest", "Living charm born in the gut of a Flukemarm. Transforms the Vengeful Spirit spell into a horde of volatile baby flukes.", 3);
    Charm charm24("Defender's Crest", "Unique charm bestowed by the King of Hallownest to his most loyal knight. Scratched and dirty, but still cared for. Causes the bearer to emit a heroic odour.", 1);
    Charm charm25("Glowing Womb", "Drains the SOUL of its bearer and uses it to birth hatchlings. The hatchlings have no desire to eat or live, and will sacrifice themselves to protect their parent.", 2);
    Charm charm26("Quick Focus", "A charm containing a crystal lens. Increases the speed of focusing SOUL, allowing the bearer to heal damage faster.", 3);
    Charm charm27("Deep Focus", "Naturally formed within a crystal over a long period. Draws in SOUL from the surrounding air. The bearer will focus SOUL at a slower rate, but the healing effect will double.", 4);
    Charm charm28("Lifeblood Heart", "Contains a living core that seeps precious lifeblood. When resting, the bearer will gain a coating of lifeblood that protects from a modest amount of damage.", 2);
    Charm charm29("Lifeblood Core", "Contains a living core that bleeds precious lifeblood. When resting, the bearer will gain a coating of lifeblood that protects from a large amount of damage.", 3);
    Charm charm30("Joni's Blessing", "Blessed by Joni, the kindly heretic. Transfigures vital fluids into blue lifeblood. The bearer will have a healthier shell and can take more damage, but they will not be able to heal themselves by focusing SOUL.", 4);
    Charm charm31("Hiveblood", "Golden nugget of the Hive's precious hardened nectar. Heals the bearer's wounds over time, allowing them to regain health without focusing SOUL.", 4);
    Charm charm32("Spore Shroom", "Composed of living fungal matter. Scatters spores when exposed to SOUL. When focusing SOUL, emit a spore cloud that slowly damages enemies", 1);
    Charm charm33("Sharp Shadow", "Contains a forbidden spell that transforms shadows into deadly weapons. When using Shadow Dash, the bearer's body will sharpen and damage enemies", 2);
    Charm charm34("Shape of Unn", "Reveals the form of Unn within the bearer. While focusing SOUL, the bearer will take on a new shape and can move freely to avoid enemies.", 2);
    Charm charm35("Nailmaster's Glory", "Contains the passion, skill and regrets of a Nailmaster. Increases the bearer's mastery of Nail Arts, allowing them to focus their power faster and unleash arts sooner.", 1);
    Charm charm36("Weaversong", "Silken charm containing a song of farewell, left by the Weavers who departed Hallownest for their old home. Summons weaverlings to give the lonely bearer some companionship and protection.", 2);
    Charm charm37("Dream Wielder", "Transient charm created for those who wield the Dream Nail and collect Essence. Allows the bearer to charge the Dream Nail faster and collect more SOUL when striking foes.", 1);
    Charm charm38("Dreamshield", "Defensive charm once wielded by a tribe that could shape dreams. Conjures a shield that follows the bearer and attempts to protect them.", 3);
    Charm charm39("Grimmchild", "Worn by those who take part in the Grimm Troupe's Ritual. The bearer must seek the Grimmkin and collect their flames. Uncollected flames will appear on the bearer's map.", 2);
    Charm charm40("Void Heart", "An emptiness that was hidden within, now unconstrained. Unifies the void under the bearer's will. This charm is a part of its bearer and can not be unequipped.", 0);

    allCharms[0] = charm1;
    allCharms[1] = charm2;
    allCharms[2] = charm3;
    allCharms[3] = charm4;
    allCharms[4] = charm5;
    allCharms[5] = charm6;
    allCharms[6] = charm7;
    allCharms[7] = charm8;
    allCharms[8] = charm9;
    allCharms[9] = charm10;

    allCharms[10] = charm11;
    allCharms[11] = charm12;
    allCharms[12] = charm13;
    allCharms[13] = charm14;
    allCharms[14] = charm15;
    allCharms[15] = charm16;
    allCharms[16] = charm17;
    allCharms[17] = charm18;
    allCharms[18] = charm19;
    allCharms[19] = charm20;

    allCharms[20] = charm21;
    allCharms[21] = charm22;
    allCharms[22] = charm23;
    allCharms[23] = charm24;
    allCharms[24] = charm25;
    allCharms[25] = charm26;
    allCharms[26] = charm27;
    allCharms[27] = charm28;
    allCharms[28] = charm29;
    allCharms[29] = charm30;

    allCharms[30] = charm31;
    allCharms[31] = charm32;
    allCharms[32] = charm33;
    allCharms[33] = charm34;
    allCharms[34] = charm35;
    allCharms[35] = charm36;
    allCharms[36] = charm37;
    allCharms[37] = charm38;
    allCharms[38] = charm39;
    allCharms[39] = charm40;

}

int main() {
    string command;
    string name;
    string clarifier;
    int index;
    int incr;

    Equipment inventory;
    Charm allCharms[MAX_CHARMS];
    setupCharmList(allCharms);
  
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

