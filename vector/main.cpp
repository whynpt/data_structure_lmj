#include<iostream>
#include"vector_int.h"
//#include"vector_int.cpp"
using namespace std;

int main()
{
	int a[10] = { 1, 3, 5, 6, 2, 4, 6 };
	int b[10] = { 1, 2, 3, 4, 5, 5, 6 };
	vector V(20, 5, 1000);
	cout << V;//  ���ֽڴ�����ֵĵ�λ
	//vector<int> V1(V); 
	//vector<int> V2(V, 1, 3);
	//vector<int> V3(b, 5);  //�������帴��û����
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
	return 0;

}

/* �ʼ�
	���������ָ��Ƴ������⣺ CRT detected that the application wrote to memory after end of heap buffer
	��copyFrom�������ٵ��������󣬽������

*/