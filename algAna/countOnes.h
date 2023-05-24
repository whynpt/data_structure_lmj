#pragma once
// O(log n)
void countOnes(int num)
{
    int count = 0, tmp = num;
    while (tmp > 0) {
        if (tmp % 2){
            count++;
        }
        tmp = tmp >> 1;
    }
    printf("num %d, %d ones \n", num, count);
}

void advanceCntOnes(int num) {
    int cnt = 0, numCpy = num;
    while (num > 0) {
        num = num & (num - 1);
        cnt++;
    }
    printf("num %d, %d ones \n", numCpy, cnt);
}