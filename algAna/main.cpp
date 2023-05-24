#include <stdio.h>
#include "countOnes.h"
#include "power2.h"
#include "binMax.h"
#include "fib.h"
#include "testdata.h"
#include <time.h>
#include <vector>
#include "hanoi.h"
using namespace fib;

// test data
int singleNum = 7;
int a[10] = { 0,2,4,6,8,1,3,5,7,9 };
int main()
{
    // testdata data(20);
    // int len = data.getlen();
    // printf("data len is %d\n", len);
    // int *intPtr = data.getarray();
    // for (int i = 0; i < len; i++) {
    //     printf("%d  ", intPtr[i]);
    // }

    // advanceCntOnes(singleNum);

    // std::vector<std::vector<double>> vec;
    // vec.push_back({1.1, 1.2});
    // printf("%f  ", vec[0][1]);

    // printf("2^%d is %d", singleNum, power2(singleNum));

    // printf("%d  ", binMax(a, 0, 10));

    // FibArray Fib1(singleNum);
    // printf("%d  ", Fib1.get());
    
    printf("%d  ", hanoi(10));

    printf("\nhello");
    return 0;
}