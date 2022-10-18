#include <iostream>
#include "Composer.h"

using namespace std;

void Composer::setName(string n){
    name = n;
}
void Composer::setDeath(int d){
    death = d;
}
string Composer::getName() const{
    return name;
}
int Composer::getDeath() const{
    return death;
}

Composer::Composer(){
    name = "unknown";
    death = 0000;
}

Composer::Composer(string n, int d){
    name = n;
    death = d;
}

Composer& Composer::operator=(const Composer& right){
    if (this != &right) {
        death = right.death;
        name = right.name;
    }
    return *this;
}

bool Composer::operator==(const Composer& right) const{
    return name == right.name;
}

bool Composer::operator!=(const Composer& right) const{
    bool match = (*this == right);
    return !match;
}

bool Composer::operator<(const Composer& right) const{
    return death < right.death;
}

bool Composer::operator<=(const Composer& right) const{
    return death <= right.death;
}

bool Composer::operator>(const Composer& right) const{
    return death > right.death;
}

ostream& operator<<(ostream& out, const Composer& obj){
    out << obj.name << " - " << obj.death << endl;
    return out;
}