#ifndef __baseLines__
#define __baseLines__

#include <fstream>

// Main structure.
class BaseLines {
public:
    char fstring[10000];

    // Destructor.
    virtual ~BaseLines() {};


    // Static input from file.
    static BaseLines *StaticIn(std::ifstream &ifdt);


    // Input from file.
    virtual void In(std::ifstream &ifdt) = 0;


    // Random input.
    static BaseLines *StaticInRnd();


    // Random input.
    virtual void InRnd() = 0;


    // Output into file.
    virtual void Out(std::ofstream &ofst) = 0;


    // Compare value for lines.
    virtual double getComparable() = 0;


    // Get char[] actual length.
    static int countLength(const char line[]);


    // Count punctuation signs in char[].
    static int countPunct(const char line[]);
};

#endif // __baseLines__