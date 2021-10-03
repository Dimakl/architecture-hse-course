#include "aphorism.h"
#include "baseLines.h"


// Inputting aphorism.
void In(aphorism &a, ifstream &ifst) {
    ifst.getline(a.fstring, 10000);
    ifst.getline(a.sstring, 10000);
}


// Creating random aphorism.
void InRnd(aphorism &a) {
    for (int i = 0; i < rand() % 10000; i++) {
        a.fstring[i] = '!' + (rand() % ('~' - '!'));
    }
    for (int i = 0; i < rand() % 10000; i++) {
        a.sstring[i] = '!' + (rand() % ('~' - '!'));
    }
}


// Outputting aphorism.
void Out(aphorism &a, ofstream &ofst) {
    ofst << "Aphorism:" << endl << a.fstring << endl << a.sstring << endl
         << "Comparison value: " << getComparable(a) << endl;
}


// Comparable value of aphorism.
double getComparable(aphorism &a) {
    int flen = countLength(a.fstring);
    int fpunc = countPunct(a.fstring);
    if (flen == 0) {
        return 1;
    }
    return (double)fpunc / flen;
}
