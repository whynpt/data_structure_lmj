#include<iostream>
#include "countOnes.h"
#include"power2.h"
#include"binMax.h"
#include"fib.h"
#include "testdata.h"
#include <time.h>
#include <vector>
#include"hanoi.h"
using namespace std;
using namespace fib;

//测试数据
int singleNum = 20;
int a[10] = { 0,2,4,6,8,1,3,5,7,9 };
int main()
{
	//vector<vector<double>> A; //动态二维数组，不能放在main()外面
	//A.push_back({ 0,1.2 });
	//cout << A[0][1];
	//testdata data(6);  // 用类存储测试数据比较麻烦
	//countOnes(singleNum);
	//printf("2^%d is %d", singleNum, power2(singleNum));
	//cout<<binMax(a, 0, 10);
	//fib_ Fib1(singleNum);
	//cout << Fib1.get() << endl;

	hanoi(20, 1);


	return 0;
}