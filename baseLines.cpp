#include "baseLines.h"


// Input from file.l
baseLines *In(ifstream &ifst) {
    baseLines *bm;
    int k;
    ifst >> k;
    char _[100];
    ifst.getline(_, 100);
    switch (k) {
        case 1:
            bm = new baseLines;
            bm->k = baseLines::APHORISM;
            In(bm->a, ifst);
            return bm;
        case 2:
            bm = new baseLines;
            bm->k = baseLines::PROVERB;
            In(bm->p, ifst);
            return bm;
        case 3:
            bm = new baseLines;
            bm->k = baseLines::RIDDLE;
            In(bm->r, ifst);
            return bm;
        default:
            throw std::invalid_argument("Invalid value of baseLine was entered - it should be in range [1; 3]");
    }
}


// Random input.
baseLines *InRnd() {
    baseLines *bm;
    int k = rand() % 3 + 1;
    switch (k) {
        case 1:
            bm = new baseLines;
            bm->k = baseLines::APHORISM;
            InRnd(bm->a);
            return bm;
        case 2:
            bm = new baseLines;
            bm->k = baseLines::PROVERB;
            InRnd(bm->p);
            return bm;
        case 3:
            bm = new baseLines;
            bm->k = baseLines::RIDDLE;
            InRnd(bm->r);
            return bm;
        default:
            return 0;
    }
}


// Output into file.
void Out(baseLines &s, ofstream &ofst) {
    switch (s.k) {
        case baseLines::APHORISM:
            Out(s.a, ofst);
            break;
        case baseLines::PROVERB:
            Out(s.p, ofst);
            break;
        case baseLines::RIDDLE:
            Out(s.r, ofst);
    }
}


// Average value of aphorism.
double getComparable(baseLines &bm) {
    switch (bm.k) {
        case baseLines::APHORISM:
            return getComparable(bm.a);
        case baseLines::PROVERB:
            return getComparable(bm.p);
        case baseLines::RIDDLE:
            return getComparable(bm.r);
        default:
            return 0.0;
    }
}

// Get char[] actual length.
int countLength(const char line[]) {
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
int countPunct(const char line[]) {
    int count = 0;
    for (int i = 0; i < 10000; i++) {
        if (ispunct(line[i])) {
            count++;
        }
    }
    return count;
}