#include <iostream>
#include "riddle.h"
#include "baseLines.h"


// Inputting riddle.
void In(riddle &r, ifstream &ifst) {
    ifst.getline(r.fstring, 10000);
    ifst.getline(r.sstring, 10000);
}


// Creating random riddle.
void InRnd(riddle &r) {
    for (int i = 0; i < rand() % 10000; i++) {
        r.fstring[i] = '!' + (rand() % ('~' - '!'));
    }
    for (int i = 0; i < rand() % 10000; i++) {
        r.sstring[i] = '!' + (rand() % ('~' - '!'));
    }
}


// Outputting riddle.
void Out(riddle &r, ofstream &ofst) {
    ofst << "Riddle:" << endl << r.fstring << endl << r.sstring << endl
    << "Comparison value: " << getComparable(r) << endl;
}


// Comparable value of riddle.
double getComparable(riddle &r) {
    int flen = countLength(r.fstring);
    int fpunc = countPunct(r.fstring);
    if (flen == 0) {
        return 1;
    }
    return (double)fpunc / flen;

}
