#include "proverb.h"
#include "baseLines.h"


// Inputting proverb.
void In(proverb &p, ifstream &ifst) {
    ifst.getline(p.fstring, 10000);
    ifst.getline(p.sstring, 10000);
}


// Creating random proverb.
void InRnd(proverb &p) {
    for (int i = 0; i < rand() % 10000; i++) {
        p.fstring[i] = '!' + (rand() % ('~' - '!'));
    }
    for (int i = 0; i < rand() % 10000; i++) {
        p.sstring[i] = '!' + (rand() % ('~' - '!'));
    }
}


// Outputting proverb.
void Out(proverb &p, ofstream &ofst) {
    ofst << "Proverb:" << endl << p.fstring << endl << p.sstring << endl
         << "Comparison value: " << getComparable(p) << endl;
}


// Comparable value of proverb.
double getComparable(proverb &p) {
    int flen = countLength(p.fstring);
    int fpunc = countPunct(p.fstring);
    if (flen == 0) {
        return 1;
    }
    return (double)fpunc / flen;
}
