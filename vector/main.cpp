#include<iostream>
#include"vector_int.h"
//#include"vector_int.cpp"
using namespace std;

int dice(int range) { return rand() % range; }//取[0, range)中的随机整数
int main()
{
	int size = 20;
	vector V;
	for (int i = 0; i < size; i++) 
		V.insert(dice( 5));
	////vector V(20, 5, 1000);//  高字节存放数字的低位
	V.print();
	V.sort(0, size);
	V.print();
	//V.remove(2, 5);
	V.uniquify();
	V.print();
	//vector<int> V1(V); 
	//vector<int> V2(V, 1, 3);
	//vector<int> V3(b, 5);  //数组整体复制没问题
	//vector<int> V4(a, 10);
	//vector<int> V5(b, 10);
	//V4.deduplicate();
	//V5.uniquify();
	//V4.print();
	//cout << endl;
	//V5.print();
	//cout<<V4;
	//cout<<V3.find(7, 1, 4);
	//V.TooLong();
	//cout << "size:"<<V.size()<<"  "<<V[2];
	//system("pause");
	return 0;

}

/* 笔记
	向量的两种复制出现问题： CRT detected that the application wrote to memory after end of heap buffer
	把copyFrom函数开辟的容量增大，解决问题

*/