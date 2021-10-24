#include "riddle.h"


// Destructor.
Riddle::~Riddle() {
    delete[] &fstring;
    delete[] &sstring;
}

// Inputting riddle.
void Riddle::In(std::ifstream &ifst) {
    ifst.getline(fstring, 10000);
    ifst.getline(sstring, 10000);
}


// Creating random riddle.
void Riddle::InRnd() {
    for (int i = 0; i < rand() % 10000; i++) {
        fstring[i] = '!' + (rand() % ('~' - '!'));
    }
    for (int i = 0; i < rand() % 10000; i++) {
        sstring[i] = '!' + (rand() % ('~' - '!'));
    }
}


// Outputting riddle.
void Riddle::Out(std::ofstream &ofst) {
    ofst << "Riddle:" << std::endl << fstring << std::endl << sstring << std::endl
    << "Comparison value: " << getComparable() << std::endl;
}


// Comparable value of riddle.
double Riddle::getComparable() {
    int flen = countLength(fstring);
    int fpunc = countPunct(fstring);
    if (flen == 0) {
        return 1;
    }
    return (double)fpunc / flen;

}
