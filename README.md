# TLB Homework

1. This code uses the `high_resolution_clock` from `std::chrono`. The period of this timer is implementation dependent, on the implementation on gyoza, it is 1ns
2. This file is `tlb.cpp`.
I create `NUMPAGES*PAGESIZE` random ints in the `data` array. To time the TLB check, I read 1 int per page of the array. I prevent prefetching by keeping a running tally, which is printed to at the end to force the compiler to actually run the computation. I print the total to cerr so that it can be separated from the result I want.

3. This script is `repeat.sh`. For all pagecounts, it repeats 100K times. It pipes stderr from the program to /dev/null so that the results can be collected by piping the output of this script to a file, for example, with `taskset --cpu-list 0 ./repeat.sh > output.dat`
