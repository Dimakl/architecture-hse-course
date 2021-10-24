#include "container.h"

#include "baseLines.h"

// Container constructor.
Container::Container(int s) {
    len = 0;
    size = s;
    cont = new BaseLines *[s];
}

// Container destructor.
Container::~Container() {
    Clear();
    delete[] *cont;
}

// Cleaning non-used memory
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}


// Thread input into container.
void Container::In(std::ifstream &ifst) {
    while (!ifst.eof()) {
        if ((cont[len] = BaseLines::StaticIn(ifst)) != 0) {
            ++len;
        }
    }
}


// Random input into container.
void Container::InRnd() {
    while (len < size) {
        if ((cont[len] = BaseLines::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}


// Output from container.
void Container::Out(std::ofstream &ofst) {
    ofst << "Container contains " << len << " elements." << std::endl;
    for (int i = 0; i < len; i++) {
        ofst << i << ": ";
        (*(cont[i])).Out(ofst);
    }
}


// Container sorting.
void Container::Sorting() {
    int i, j;
    BaseLines *bLine;
    for (i = 1; i < len; i++) {
        bLine = cont[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && (cont[j])->getComparable() > bLine->getComparable()) {
            *cont[j + 1] = *cont[j];
            j = j - 1;
        }
        *cont[j + 1] = *bLine;
    }
}
