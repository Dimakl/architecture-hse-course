#include <cstdlib>
#include <ctime>
#include <cstring>

#include "container.h"


// Error message.
void errMessage1() {
    printf("incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}


// Error message.
void errMessage2() {
    printf("incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}


const int max_len = 10000;

int main(int argc, char *argv[]) {
    // Wrong number of arguments.
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    // Initialization.
    printf("Start\n");
    Container *c = nullptr;
    // File input.
    try {
        if (!strcmp(argv[1], "-f")) {
            c = new Container(max_len);
            std::ifstream ifst(argv[2]);
            c->In(ifst);
        // Random input.
        } else if (!strcmp(argv[1], "-n")) {
            int size = atoi(argv[2]);
            if ((size < 1) || (size > 10000)) {
                printf("incorrect number of objects = %d. Set 0 < number <= 10000\n", size);
                return 3;
            }
            srand(static_cast<unsigned int>(time(0)));
            c = new Container(size);
            c->InRnd();

        } else {
            errMessage2();
            return 2;
        }
    } catch (std::invalid_argument e) {
        printf(e.what());
        return 3;
    }

    // Unsorted container output.
    std::ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c->Out(ofst1);

    // Sorted container output.
    std::ofstream ofst2(argv[4]);
    c->Sorting();
    ofst2 << "Sorted container:" << "\n";
    c->Out(ofst2);

    // End.
    delete c;
    printf("Stop");
    return 0;
}
