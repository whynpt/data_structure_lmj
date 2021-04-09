#include<iostream>
#include "binMax.h"
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int binMax(int arr[], int start, int end)  //ϣ���ܹ�ʵ��ͬʱ�������ֵ���±�
{	
	if (start == end - 1) // ����ҿ����䣬ֻ��һ��Ԫ�أ�����Ψһ��Ԫ��
		return arr[start];
	int mi = (start + end) >> 1;
	return max(binMax(arr, start, mi), 
				binMax(arr, mi, end));  //���Թ�����startһ�������ӣ�˵����ִ�ж��ź��binMax����
}

