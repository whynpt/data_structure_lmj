#include<iostream>
#include"vector.h"
#include"vector.cpp"
using namespace std;

int main()
{
	int a[10] = { 1, 3, 5, 6, 2, 4, 6 };
	//int b[10] = { 1, 2, 3, 4, 5, 6 };
	//vector<int> V(20, 5, 1000); //  高字节存放数字的低位
	//vector<int> V1(V); 
	//vector<int> V2(V, 1, 3);
	//vector<int> V3(b, 5);  //数组整体复制没问题
	vector<int> V4(a, 10);
	V4.deduplicate()
	//cout<<V3.find(7, 1, 4);
	//V.TooLong();
	cout << "size:"<<V.size()<<"  "<<V[2];
	return 0;
	cout
}

/* 笔记
	向量的两种复制出现问题： CRT detected that the application wrote to memory after end of heap buffer
	把copyFrom函数开辟的容量增大，解决问题

*/