#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <iterator>
#include <limits.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        exit(1);
    }
    int NUMPAGES = atoi(argv[1]);
    long PAGESIZE = sysconf(_SC_PAGESIZE);
    int REPETITIONS = atoi(argv[2]);
    std::chrono::time_point<std::chrono::steady_clock> start;
    std::chrono::time_point<std::chrono::steady_clock> end;

    int i, j, jump = PAGESIZE / sizeof(int);
    int* data = (int*) calloc(NUMPAGES * PAGESIZE / sizeof(int), sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < NUMPAGES * PAGESIZE / sizeof(int); i++) {
        data[i] = (rand() % (1000 - -1000 + 1)) + -1000;
    }
    int total = 0;
    start = std::chrono::steady_clock::now();
    for (j = 0; j < REPETITIONS; j++) {
        for (i=0; i < NUMPAGES * jump; i += jump) {
            total += data[i];
        }
    }
    end = std::chrono::steady_clock::now();
    std::cerr << total << std::endl;
    std::chrono::nanoseconds total_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << NUMPAGES << "\t" << total_time.count()  / REPETITIONS << "ns" << std::endl;
    free(data);
    return 0;
}

// 256 pages = 1M REPETITIONS
//   4 pages = 100M
