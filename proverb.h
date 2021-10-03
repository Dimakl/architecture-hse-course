#ifndef __proverb__
#define __proverb__


#include <fstream>


using namespace std;


// proverb structure.
struct proverb {
    char fstring[10000], sstring[10000];
};


// Inputting proverb.
void In(proverb &p, ifstream &ifst);


// Creating proverb.
void InRnd(proverb &p);


// Outputting proverb.
void Out(proverb &p, ofstream &ofst);


// Comparable value of proverb.
double getComparable(proverb &p);


#endif // __proverb__
