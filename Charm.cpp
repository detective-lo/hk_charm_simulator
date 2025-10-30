#include <iostream>

using namespace std;

#include "Charm.h"

Charm::Charm() {
    name = "";
    desc = "";
    notches = 0;
}

Charm::Charm(string name, string desc, int notches) {
    this->name = name;
    this->desc = desc;
    this-> notches = notches;
}

string Charm::getName() const {
    return name;
}

void Charm::setName(string name) {
    this->name = name;
}

string Charm::getDescription() const {
    return desc;
}

void Charm::setDescription(string desc) {
    this->desc = desc;
}

int Charm::getNotches() const {
    return notches;
}

void Charm::setNotches(int notches) {
    this->notches = notches;
}

string Charm::getInfo() const {
    string info;
    info = "    " + name + " ";
    
    for (int i = 0; i < notches; i++) {
        info += "[X]";
    }
    return info;
}

string Charm::getInfoWithDesc() const {
    string info;
    info = "    " + name + " ";
    
    for (int i = 0; i < notches; i++) {
        info += "[X]";
    }

    info += "\n    " + desc;
    return info;
}
