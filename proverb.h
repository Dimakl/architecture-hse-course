#ifndef __proverb__
#define __proverb__


#include <fstream>
#include "baseLines.h"


// proverb structure.
class Proverb : public BaseLines {
private:
    char sstring[10000];
public:
    // Destructor.
    virtual ~Proverb();


    // Inputting proverb.
    virtual void In(std::ifstream &ifst);


    // Creating proverb.
    virtual void InRnd();


    // Outputting proverb.
    virtual void Out(std::ofstream &ofst);


    // Comparable value of proverb.
    virtual double getComparable();
};

#endif // __proverb__
