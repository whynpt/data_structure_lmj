#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<iomanip>


void print(vector<int> v)
{
	for (auto n : v)
		cout << setw(4)<<n;
	cout << endl;
}

bool isSorted(vector<int>& v, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		if (v[i] > v[i+1])
			return false;
	}
	return true;
}