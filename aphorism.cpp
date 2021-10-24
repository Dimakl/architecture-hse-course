#include "aphorism.h"


// Destructor.
Aphorism::~Aphorism() {
    delete[] &fstring;
    delete[] &sstring;
}


// Inputting aphorism.
void Aphorism::In(std::ifstream &ifst) {
    ifst.getline(fstring, 10000);
    ifst.getline(sstring, 10000);
}


// Creating random aphorism.
void Aphorism::InRnd() {
    for (int i = 0; i < rand() % 10000; i++) {
        fstring[i] = '!' + (rand() % ('~' - '!'));
    }
    for (int i = 0; i < rand() % 10000; i++) {
        sstring[i] = '!' + (rand() % ('~' - '!'));
    }
}


// Outputting aphorism.
void Aphorism::Out(std::ofstream &ofst) {
    ofst << "Aphorism:" << std::endl << fstring << std::endl << sstring << std::endl
         << "Comparison value: " << getComparable() << std::endl;
}


// Comparable value of aphorism.
double Aphorism::getComparable() {
    int flen = BaseLines::countLength(fstring);
    int fpunc = BaseLines::countPunct(fstring);
    if (flen == 0) {
        return 1;
    }
    return (double)fpunc / flen;
}
