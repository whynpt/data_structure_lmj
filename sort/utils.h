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

bool isHeap(vector<int>& v, int start, int end)
{
	int len = end - start + 1;
	int i = ceil((len - 1) / 2) - 1;
	for (; i >= 0; i--)
	{
		int left = 2 * i + 1, right = 2 * i + 2;
		if (v[i] < v[left] || v[i] < v[right])
			return false;
	}
	return true;
}