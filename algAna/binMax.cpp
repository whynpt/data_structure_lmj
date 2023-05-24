#include<iostream>
#include "binMax.h"
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int binMax(int arr[], int start, int end)  //希望能够实现同时返回最大值和下标
{    
    if (start == end - 1) {
        return arr[start];
    }
    int mi = (start + end) >> 1;
    return max(binMax(arr, start, mi), 
        binMax(arr, mi, end));  // latter is called first
}

