#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include"utils.h"
using namespace std;


void  bubbleSort(vector<int>& v, int start, int end) //必须有两层循环，外层控制是否进行扫描，内层遍历进行扫描
{
	/*
1 必须有两层循环，外层控制是否进行扫描，内层遍历进行扫描
2 last必须能同时影响两个循环，但不能写在for的判断条件里，因为一次扫描就可能改变last值
当 j+1与j比较时
3 内层遍历区间左闭右开，区间右端值end - 1（无法达到）表示该趟扫描能将该位置（end-1）元素放置完好，一次循环只能有一个变量在自增或自减
4 逆序对右值赋给last和end，因为左值未放置完好
*/
//版本c
	int last = end, count = 0;
	while (end > start)
	{
		for (int j = start; j < end - 1; j++)
		{
			last = 0;  // 没有逆序对也等于last为首位置
			if (v[j + 1] < v[j])
			{
				swap(v[j + 1], v[j]);
				last = j + 1;  //last记录逆序对的右值
			}
			count++;	//print();		
		}
		cout << "新循环结束" << last << endl;
		end = last;
	}
	//版本B
	//for (bool ordered = false; ordered = !ordered; end--)
	//	for (int j = start; j < end -1; j++)
	//	{
	//		if (v[j + 1] < v[j])
	//		{
	//			ordered = false,
	//				swap(v[j + 1], v[j]);
	//		} 
	//		count++;
	//	}
	//版本A
	//for (int i = start; i < end; i++)
	//	for (int j = start; j < end - i - 1; j++)
	//	{
	//		if (v[j + 1] < v[j])
	//			swap(v[j + 1], v[j]);
	//		count++;
	//	}
	cout << "比较次数" << count << endl;
}


void merge(vector<int>& v, int start, int mid, int end)
{
	int lenL = mid - start + 1, lenR = end - mid;
	vector<int> left(v.begin() + start, v.begin() + mid + 1), right(v.begin() + mid + 1, v.begin() + end + 1);
	int l = 0, r = 0;
	while (lenL > 0 && lenR > 0) // 如果left和right都不空
	{
		if (left[l] > right[r])  // 较小者进入原数组
		{
			v[start++] = right[r++]; lenR--; //cout << v[start - 1]<<" ";
		}
		else
		{
			v[start++] = left[l++]; lenL--; //cout << v[start - 1] << " ";
		}

	}
	while (lenL > 0)
	{
		v[start++] = left[l++]; lenL--; //cout << v[start - 1] << " ";
	}

}

void mergeSort(vector<int>& v, int start, int end)
{
	if (end == start)  //只会中止继续调用mergesort，不会不进入merge
		return;
	int mid = (start + end) >> 1;
	mergeSort(v, start, mid);
	mergeSort(v, mid + 1, end);
	merge(v, start, mid, end);	//每次调用该函数，这三个参数都是向量的真实下标，独一无二

}


int partition(vector<int>& v, int start, int end)
{
	int p = v[start];
	int i = start, j = end;
	while (i < j)
	{
		while (v[j] >= p && i < j)
			j--;
		v[i] = v[j];
		while (v[i] < p && i < j)
			i++;
		v[j] = v[i];
	}
	v[i] = p;
	return i;
}

void quickSort(vector<int>& v, int start, int end)
{
	if (end < 0)
		return;
	if (start >= end)
		return;
	int mid = partition(v, start, end);
	quickSort(v, start, mid - 1);
	quickSort(v, mid + 1, end);
}


void selectionSort(vector<int>& v, int start, int end)
{
	int min_num, min_index;
	for (int i = start; i < end; i++)
	{
		min_num = v[i];
		min_index = i;
		for (int j = i + 1; j <= end; j++)
		{
			if (min_num > v[j])
			{
				min_num = v[j];
				min_index = j;
			}
		}
		swap(v[i], v[min_index]);
	}
}


void insertionSort(vector<int>& v, int start, int end)
{
	for (int i = start+1; i <= end; i++)
	{
		int j = i - 1, insertnum = v[i];  //v[i]待插入的元素
		//while (j >=0 && v[j] > v[j+1])  //先判断j>=0
		//{
		//	swap(v[j], v[j+1]);  //swap含三次赋值，比一次赋值慢
		//	j--;
		//}
		while (j >= 0 && v[j] > insertnum)
		{
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = insertnum;
	}
}


void jumpPrint(vector<int> v, int start, int end, int gap)
{
	for (int i = start; i < start + gap; i++)
	{
		for (int j = i; j < end; j += gap)
			cout << setw(4) << v[j] << " ";
		cout << endl;
	}
}
void shellSort(vector<int>& v, int start, int end)
{
	int len = end - start + 1, gap = 1;
	while ((gap-1) < len)
		gap = gap << 1;  //单纯移位不会改变gap值
	gap = (gap >> 1) -1;  // 第一次分为k组. 移位优先级低于加减法
	while (gap > 0)  //间隔缩短至1
	{
		for (int i = start; i < start+gap; i++)  //从start开始，可以实现区间排序。依次对第i各组个组进行插入排序
		{
			
			for (int j = i + gap; j <= end; j += gap)  //插入排序
			{
				int k = j - gap;  //k遍历插入排序中有序的那一部分数组,k是待插入元素的前一个下标
				int insertnum = v[j]; 
				while (k >= 0 && v[k] > insertnum)
				{
					v[k + gap] = v[k];
					k-=gap;
				}
				k += gap;
				v[k] = insertnum;
			}
			//print(v);
			//jumpPrint(v, start, end, gap);
		}
		gap = gap>>1;
	}
}


void heapSort(vector<int>& v, int start, int end)
{

}


void radixSort(vector<int>& v, int start, int end)
{

}