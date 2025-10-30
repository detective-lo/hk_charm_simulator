#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>
#include <string>

using namespace std;

#include "Charm.h"

class Equipment {
    private:
        Charm *charms; // Equipped charms
        int maxNotches;
        int usedNotches;
        int maxCharms;
        int usedCharms;
        bool overcharmed;
    public:
        Equipment();
        Equipment(int maxNotches);
        ~Equipment();
        Equipment(const Equipment& other);

        int getMaxNotches() const;
        void setMaxNotches(int maxNotches);
        int getUsedNotches() const;
        void setUsedNotches(int usedNotches);

        int getMaxCharms() const;
        void setMaxCharms(int maxCharms);
        int getUsedCharms() const;
        void setUsedCharms(int usedCharms);

        bool equipCharm(Charm chosenCharm);
        bool removeCharm(Charm chosenCharm);

        void incrNotches(int incr);
        void incrCharms(int incr);

        bool getOvercharmed() const;
        void flipOvercharmed();

        string getCharmInfo() const;
        string getNotchInfo() const;
};

#endif