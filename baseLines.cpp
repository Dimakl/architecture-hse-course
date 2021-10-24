#include "baseLines.h"
#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"


// Input from file.
BaseLines *BaseLines::StaticIn(std::ifstream &ifst) {
    int k = 0;
    ifst >> k;
    char _[100];
    ifst.getline(_, 100);
    BaseLines* bm;
    switch (k) {
        case 1:
            bm = new Aphorism;
            break;
        case 2:
            bm = new Proverb;
            break;
        case 3:
            bm = new Riddle;
            break;
        default:
            throw std::invalid_argument("Invalid value of baseLine was entered - it should be in range [1; 3]");
    }
    bm->In(ifst);
    return bm;
}


// Random input.
BaseLines *BaseLines::StaticInRnd() {
    BaseLines *bm;
    int k = rand() % 3 + 1;
    switch (k) {
        case 1:
            bm = new Aphorism;
            break;
        case 2:
            bm = new Proverb;
            break;
        case 3:
            bm = new Riddle;
            break;
        default:
            return 0;
    }
    bm->InRnd();
    return bm;
}


// Get char[] actual length.
int BaseLines::countLength(const char line[]) {
    int length = 10000;
    for (int i = 9999; i >= 0; i--) {
        if (line[i] != '\000') {
            break;
        }
        length--;
    }
    return length;
}

// Count punctuation signs in char[].
int BaseLines::countPunct(const char line[]) {
    int count = 0;
    for (int i = 0; i < 10000; i++) {
        if (ispunct(line[i])) {
            count++;
        }
    }
    return count;
}