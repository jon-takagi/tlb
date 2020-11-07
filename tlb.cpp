#include <iostream>
#include <limits.h>
#include <unistd.h>
#include <chrono>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        exit(1);
    }
    int NUMPAGES = atoi(argv[1]);
    long PAGESIZE = sysconf(_SC_PAGESIZE);
    int REPETITIONS = 10000000 / NUMPAGES;
    int i, j, jump = PAGESIZE / sizeof(int);
    int a[NUMPAGES * PAGESIZE];
    for (i = 0; i < NUMPAGES * jump; i+= jump) {
        a[i] = 0;
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    start = std::chrono::high_resolution_clock::now();
    for (j = 0; j < REPETITIONS; j++) {
        for (i=0; i < NUMPAGES * jump; i += jump) {
            a[i] += 1;
        }
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds total_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << NUMPAGES << "\t" << total_time.count()  / REPETITIONS << "ns" << std::endl;
    return 0;
}

// 256 pages = 1M REPETITIONS
//   4 pages = 100M
