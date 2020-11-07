#!/bin/bash
for i in {1..10}
do
    ./tlb.bin $((2**i)) 100000 2>/dev/null
done
