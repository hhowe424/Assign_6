#ifndef ASSIGNMENT_6_COMPOSER_H
#define ASSIGNMENT_6_COMPOSER_H

#include <iostream>
#include <fstream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

class Composer {
private:
    string name;
    int death;
public:
    void setName(string n);
    void setDeath(int d);
    string getName() const;
    int getDeath() const;

    Composer();
    Composer(string n, int d);
    Composer& operator=(const Composer& right);
    bool operator==(const Composer& right) const;
    bool operator!=(const Composer& right) const;
    bool operator<(const Composer& right) const;
    bool operator<=(const Composer& right) const;
    bool operator>(const Composer& right) const;

    friend ostream& operator<<(ostream& out, const Composer& obj);
    friend istream& operator>>(istream& in, Composer& obj);
};
ostream& operator<<(ostream& out, const Composer& obj);
istream& operator>>(istream& in, Composer& obj);

#endif //ASSIGNMENT_6_COMPOSER_H
