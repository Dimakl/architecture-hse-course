#ifndef __riddle__
#define __riddle__


#include <fstream>
#include "baseLines.h"


// riddle structure.
class Riddle : public BaseLines {
private:
    char sstring[10000];
public:
    // Destructor.
    virtual ~Riddle();


    // Inputting riddle.
    virtual void In(std::ifstream &ifst);


    // Creating riddle.
    virtual void InRnd();


    // Outputting riddle.
    virtual void Out(std::ofstream &ofst);


    // Comparable value of riddle.
    virtual double getComparable();
};

#endif // __riddle__
