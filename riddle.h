#ifndef __riddle__
#define __riddle__


#include <fstream>




// Riddle structure.
struct riddle {
    char fstring[10000], sstring[10000];
};


// Inputting riddle.
void In(riddle &r, std::ifstream &ifst);


// Creating riddle.
void InRnd(riddle &r);


// Outputting riddle.
void Out(riddle &r, std::ofstream &ofst);


// Comparable value of riddle.
double getComparable(riddle &r);


#endif // __riddle__
