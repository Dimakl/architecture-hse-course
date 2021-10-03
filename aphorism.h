#ifndef __aphorism__
#define __aphorism__


#include <fstream>


using namespace std;


// aphorism structure.
struct aphorism {
    char fstring[10000], sstring[10000];
};


// Inputting aphorism.
void In(aphorism &a, ifstream &ifst);


// Creating aphorism.
void InRnd(aphorism &a);


// Outputting aphorism.
void Out(aphorism &a, ofstream &ofst);


// Comparable value of aphorism.
double getComparable(aphorism &a);


#endif // __aphorism__
