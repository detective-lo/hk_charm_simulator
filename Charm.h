#ifndef CHARM_H
#define CHARM_H

#include <iostream>
#include <string>

using namespace std;

class Charm {
    private:
        string name;
        string desc;
        int notches;
    public:
        Charm();
        Charm(string, string, int);
        string getName() const;
        void setName(string);
        string getDescription() const;
        void setDescription(string);
        int getNotches() const;
        void setNotches(int);
        string getInfo() const;
        string getInfoWithDesc() const;
};

#endif