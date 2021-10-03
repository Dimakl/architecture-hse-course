#ifndef __baseLines__
#define __baseLines__


#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"

// Main structure.
struct baseLines {

    // Each type of aphorism enumerated.
    enum key {
        APHORISM, PROVERB, RIDDLE
    };
    key k;
    union {
        aphorism a;
        proverb p;
        riddle r;
    };
};

// Input from file.
baseLines *In(ifstream &ifdt);


// Random input.
baseLines *InRnd();


// Output into file.
void Out(baseLines &bm, ofstream &ofst);


// Compare value for lines.
double getComparable(baseLines &bm);

// Get char[] actual length.
int countLength(const char line[]);

// Count punctuation signs in char[].
int countPunct(const char line[]);


#endif // __baseLines__