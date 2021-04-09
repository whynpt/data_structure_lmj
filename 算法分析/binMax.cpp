#include<iostream>
#include "binMax.h"
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int binMax(int arr[], int start, int end)  //希望能够实现同时返回最大值和下标
{	
	if (start == end - 1) // 左闭右开区间，只有一个元素，返回唯一的元素
		return arr[start];
	int mi = (start + end) >> 1;
	return max(binMax(arr, start, mi), 
				binMax(arr, mi, end));  //调试过程中start一步步增加，说明先执行逗号后的binMax（）
}

