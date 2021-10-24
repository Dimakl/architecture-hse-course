#ifndef __aphorism__
#define __aphorism__


#include <fstream>
#include "baseLines.h"


// aphorism structure.
class Aphorism : public BaseLines {
private:
    char sstring[10000];
public:
    // Destructor.
    virtual ~Aphorism();


    // Inputting aphorism.
    virtual void In(std::ifstream &ifst);


    // Creating aphorism.
    virtual void InRnd();


    // Outputting aphorism.
    virtual void Out(std::ofstream &ofst);


    // Comparable value of aphorism.
    virtual double getComparable();
};

#endif // __aphorism__
