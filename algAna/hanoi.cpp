#include"hanoi.h"
#include<iostream>

int hanoi(int num)
{
    if (num <= 1) {
        return num;
    }

    // move n-1 block away (keep order), then move block at bottom, finally move n-1 blocks back (keep order)
    return 2 * hanoi(num - 1) + 1;
}