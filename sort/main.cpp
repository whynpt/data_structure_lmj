#include<iostream>
#include<vector>
#include<stdlib.h>
#include"sort.h"
using namespace std;


int main()
{
	vector<int> v;
	int len = 15, MaxNum = 100, seed = 1234;
	int a[5] = { 1, 1, 1 };
	srand(seed);
	for (int i = 0; i < len; i++)
		v.push_back(rand()%MaxNum);
	cout << "origin vector:"<<endl;
	print(v);
	shellSort(v, 0, len - 1);
	if (!isSorted(v, 0, len - 1))
	{
		cout <<"vector is sorted wrong!"<<endl;
		return 0;
	}
	cout << "sorted vector:" << endl;
	print(v);
	return 0;
}