#include "proverb.h"


// Destructor.
Proverb::~Proverb() {
    delete[] &fstring;
    delete[] &sstring;
}


// Inputting proverb.
void Proverb::In(std::ifstream &ifst) {
    ifst.getline(fstring, 10000);
    ifst.getline(sstring, 10000);
}


// Creating random proverb.
void Proverb::InRnd() {
    for (int i = 0; i < rand() % 10000; i++) {
        fstring[i] = '!' + (rand() % ('~' - '!'));
    }
    for (int i = 0; i < rand() % 10000; i++) {
        sstring[i] = '!' + (rand() % ('~' - '!'));
    }
}


// Outputting proverb.
void Proverb::Out(std::ofstream &ofst) {
    ofst << "Proverb:" << std::endl << fstring << std::endl << sstring << std::endl
         << "Comparison value: " << getComparable() << std::endl;
}


// Comparable value of proverb.
double Proverb::getComparable() {
    int flen = countLength(fstring);
    int fpunc = countPunct(fstring);
    if (flen == 0) {
        return 1;
    }
    return (double)fpunc / flen;
}
