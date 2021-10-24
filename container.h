#ifndef __container__
#define __container__


#include <fstream>
#include "baseLines.h"


// Container class.
class Container {
private:
    int len;
    int size;
    BaseLines **cont;

public:


    // Container constructor.
    Container(int s);


    // Container destructor.
    ~Container();


    // Cleaning non-used memory.
    void Clear();


    // Thread input into container.
    void In(std::ifstream &ifst);


    // Random input into container.
    void InRnd();


    // Output from container.
    void Out(std::ofstream &ofst);


    // Container sorting.
    void Sorting();
};


#endif // __container__