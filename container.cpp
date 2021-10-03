#include "container.h"


// Container initialization.
void Init(container &c) {
    c.len = 0;
}


// Cleaning non-used memory
void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}


// Thread input into container.
void In(container &c, ifstream &ifst) {
    while (!ifst.eof()) {
        if ((c.cont[c.len] = In(ifst)) != 0) {
            ++c.len;
        }
    }
}


// Random input into container.
void InRnd(container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}


// Output from container.
void Out(container &c, ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << endl;
    for (int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
    }
}


// Container sorting.
void Sorting(container &c) {
    int i, j;
    baseLines bLine{};
    for (i = 1; i < c.len; i++) {
        bLine = *c.cont[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && getComparable(*c.cont[j]) > getComparable(bLine)) {
            *c.cont[j + 1] = *c.cont[j];
            j = j - 1;
        }
        *c.cont[j + 1] = bLine;
    }
}
