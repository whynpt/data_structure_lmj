#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include"utils.h"
using namespace std;


void  bubbleSort(vector<int>& v, int start, int end) //����������ѭ�����������Ƿ����ɨ�裬�ڲ��������ɨ��
{
	/*
1 ����������ѭ�����������Ƿ����ɨ�裬�ڲ��������ɨ��
2 last������ͬʱӰ������ѭ����������д��for���ж��������Ϊһ��ɨ��Ϳ��ܸı�lastֵ
�� j+1��j�Ƚ�ʱ
3 �ڲ������������ҿ��������Ҷ�ֵend - 1���޷��ﵽ����ʾ����ɨ���ܽ���λ�ã�end-1��Ԫ�ط�����ã�һ��ѭ��ֻ����һ���������������Լ�
4 �������ֵ����last��end����Ϊ��ֵδ�������
*/
//�汾c
	int last = end, count = 0;
	while (end > start)
	{
		for (int j = start; j < end - 1; j++)
		{
			last = 0;  // û�������Ҳ����lastΪ��λ��
			if (v[j + 1] < v[j])
			{
				swap(v[j + 1], v[j]);
				last = j + 1;  //last��¼����Ե���ֵ
			}
			count++;	//print();		
		}
		cout << "��ѭ������" << last << endl;
		end = last;
	}
	//�汾B
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
	//�汾A
	//for (int i = start; i < end; i++)
	//	for (int j = start; j < end - i - 1; j++)
	//	{
	//		if (v[j + 1] < v[j])
	//			swap(v[j + 1], v[j]);
	//		count++;
	//	}
	cout << "�Ƚϴ���" << count << endl;
}


void merge(vector<int>& v, int start, int mid, int end)
{
	int lenL = mid - start + 1, lenR = end - mid;
	vector<int> left(v.begin() + start, v.begin() + mid + 1), right(v.begin() + mid + 1, v.begin() + end + 1);
	int l = 0, r = 0;
	while (lenL > 0 && lenR > 0) // ���left��right������
	{
		if (left[l] > right[r])  // ��С�߽���ԭ����
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
	if (end == start)  //ֻ����ֹ��������mergesort�����᲻����merge
		return;
	int mid = (start + end) >> 1;
	mergeSort(v, start, mid);
	mergeSort(v, mid + 1, end);
	merge(v, start, mid, end);	//ÿ�ε��øú���������������������������ʵ�±꣬��һ�޶�

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
		int j = i - 1, insertnum = v[i];  //v[i]�������Ԫ��
		//while (j >=0 && v[j] > v[j+1])  //���ж�j>=0
		//{
		//	swap(v[j], v[j+1]);  //swap�����θ�ֵ����һ�θ�ֵ��
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
		gap = gap << 1;  //������λ����ı�gapֵ
	gap = (gap >> 1) -1;  // ��һ�η�Ϊk��. ��λ���ȼ����ڼӼ���
	while (gap > 0)  //���������1
	{
		for (int i = start; i < start+gap; i++)  //��start��ʼ������ʵ�������������ζԵ�i���������в�������
		{
			
			for (int j = i + gap; j <= end; j += gap)  //��������
			{
				int k = j - gap;  //k���������������������һ��������,k�Ǵ�����Ԫ�ص�ǰһ���±�
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