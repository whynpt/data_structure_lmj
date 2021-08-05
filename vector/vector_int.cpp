#include"vector_int.h"
#include<iostream>
using namespace std;


//默认构造函数

vector ::vector(int c, int s, int v)
{
	_elem = new int[_capacity = 2 * c];
	for (_size = 0; _size < s; _elem[_size++] = v);
	//_elem[_size] = v;
};

//数组整体复制

vector ::vector(int const* A, int n)
{
	_elem = new int[_capacity = n];
	copyFrom(A, 0, n);
}

//数组区间复制

vector ::vector(int const* A, int start, int end)
{
	copyFrom(A, start, end);
}

//向量整体复制

vector ::vector(vector const& V)
{
	copyFrom(V._elem, 0, V._size);
}

//数组区间复制

vector ::vector(vector const& V, int start, int end)
{
	copyFrom(V._elem, start, end);
}

//复制函数

void vector::copyFrom(int const* A, int start, int end)
{
	_elem = new int[_capacity = 2 * (end - start)];
	for (_size = 0; start < end; _size++, start++)
	{
		_elem[_size] = A[start];
	}
};

//读取元素个数

int vector::size() const
{
	return _size;
}

//无序整体查找

int vector::find(int const e)
{
	return find(e, 0, size());
}

//无序区间查找

int vector::find(int const e, int start, int end)
{
	while (start < end)
	{
		if (e == _elem[start])
			return start;
		start++;
	}
	return -1;
}

//有序整体查找

int vector::search(int const e)
{
	return search(e, 0, size());
}

//有序区间查找

int vector::search(int const e, int start, int end)
{
	if (e < _elem[start] || e > _elem[end])
		return -1;
	while (start < end)
	{
		if (e == _elem[start])
			return start;
		start++;
	}
	return -1;
}

//扩容

void vector::expand()
{
	int* newelem = new int[_capacity = _capacity * 2];
	for (int i = 0; i < _size; i++)
	{
		newelem[i] = _elem[i];
	}
	delete[] _elem;
	_elem = newelem;

}

//缩容

void vector::shrink()
{
	int* newelem = new int[_capacity = _size * 2];
	for (int i = 0; i < _size; i++)
	{
		newelem[i] = _elem[i];
	}
	delete[] _elem;
	_elem = newelem;
}


void vector::TooLong()
{
	if (_capacity > _size * 4)
		shrink();
}


void vector::TooShort()
{
	if (_capacity <= _size * 2)
		expand();
}

//重载[]

int& vector::operator[] (int r)
{
	return _elem[r];
}

//重载[]

const int& vector::operator[] (int r) const
{
	return _elem[r];
}

//重载<<
//ostream& operator<<(ostream& out, const vector& V)
//{
//	for(int i = 0; i < V.size(); i++)
//	out << V[i] << "  ";
//	return out;
//}

//重载=
//vector& operator= (vector const& V, int start, int end)
//{
//	//int* newelem = new int [_capaci;
//}

//区间删除

int vector::remove(int start, int end)
{
	int tmp = end;  // 需移动元素的首下标
	while (end < _size)
		_elem[start++] = _elem[end++];
	_size -= (end - start);
	TooLong();  // 判断删除后的向量是否需要缩容
	return _size;
}

//单个元素删除

int vector::remove(int r)
{
	while (r++ < _size)
		_elem[r] = _elem[r + 1];
	_size--;
	return _size;
}

//指定位置插入

int vector::insert(int const& e, int r)   //先将后面的移位， 再插入新元素
{
	int old_size = _size;
	while (old_size >= r)
	{
		TooShort();
		_elem[old_size] = _elem[old_size - 1];  
		old_size--;
	}
	_elem[r] = e;

	return ++_size;
}

//末尾插入

int vector::insert(int const& e)
{
	insert(e, _size);
	return _size;

}

//无序去重

int vector::deduplicate()
{
	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size; j++)
		{
			if (_elem[i] == _elem[j] && i != j)
				remove(i);
			_size--;
		}
	return _size;
}

//有序去重
int vector::uniquify()
{
	int start = 0, num2remove;  //  num2remove：某次去重需要删除的元素数
	for (int r = 0; r < _size - 1; r++)
	{
		if ((_elem[r] != _elem[r + 1]) && (start < r))  // r + 1是新元素的起点，如果相邻起点相距不小于2： start + 2 <= r + 1，则有重复元素
		{	
			remove(start + 1, r + 1);
			num2remove = r - start;
			start++; // 新元素加一
			r = start;
		}
		print();
	}
	if(start != _size - 1)
		remove(start + 1, _size);
	return _size;
}

//打印向量
void vector::print()
{
	cout << "容量：" << _capacity << "\n元素个数：" << _size<< endl;
	int r = 0;
	while (r < _size)
	{
		cout << _elem[r] << "  ";
		r++;
	}
	cout<<endl;
}

//排序
void vector::sort(int start, int end)
{
	switch (rand() % 2)
	{	
		case 1:mergeSort(start , end); break;
		default:  bubbleSort(start, end); break;
	}

}

//起泡排序
void vector::bubbleSort(int start, int end) //必须有两层循环，外层控制是否进行扫描，内层遍历进行扫描
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
	while(end > start)
	{
		for (int j = start; j < end -1; j++)
		{
			last = 0;  // 没有逆序对也等于last为首位置
			if (_elem[j + 1] < _elem[j])
			{
				swap(_elem[j + 1], _elem[j]);
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
	//		if (_elem[j + 1] < _elem[j])
	//		{
	//			ordered = false,
	//				swap(_elem[j + 1], _elem[j]);
	//		} 
	//		count++;
	//	}
	//版本A
	//for (int i = start; i < end; i++)
	//	for (int j = start; j < end - i - 1; j++)
	//	{
	//		if (_elem[j + 1] < _elem[j])
	//			swap(_elem[j + 1], _elem[j]);
	//		count++;
	//	}
	cout << "比较次数" << count << endl;
}

//归并排序
void vector::mergeSort(int start, int end)
{
	if (end - start < 2)  //只会中止继续调用mergeSort，不会不进入merge
		return;
	int mid = (start + end) >> 1;
	mergeSort(start, mid);
	mergeSort(mid, end);
	merge(start, mid, end);	//每次调用该函数，这三个参数都是向量的真实下标，独一无二

}

//向量归并
void vector::merge(int start, int mid, int end)  //慎用_elem,因为它代表整个原始向量，merge函数只是对部分向量进行操作，滥用会修改向量的其他区域
{
	int lenL = mid - start, lenR = end - mid;
	int* left = new int[lenL];  //开辟新内存，放置左半部分向量，中括号内有待优化
	for (int j = 0, i = start; i < mid; i++, j++)  // 不能从0 开始赋值，要注意当前区间
		left[j] = _elem[i];
	int* right = _elem + mid;  //实际上查看内存，第一次进入该函数可以看到原数组的首元素赋给了left，其他的赋给了right
	int l = 0, r = 0;
	while (lenL > 0 && lenR > 0) // 如果left和right都不空
	{
		if (left[l] > right[r])  // 较小者进入原数组
		{
			_elem[start++] = right[r++]; lenR--; //cout << _elem[start - 1]<<" ";
		}
		else
		{
			_elem[start++] = left[l++]; lenL--; //cout << _elem[start - 1] << " ";
		}
		
	}
	while (lenL > 0)
		{
			_elem[start++] = left[l++]; lenL--; //cout << _elem[start - 1] << " ";
		}
	//cout << endl;
	delete[] left;

	//int lb = mid - start, lc = end - mid;
	//int* A = _elem + start;
	//int* B = new int[lb];
	//int* C = _elem + mid;
	//for (int i = 0; i < lb; i++)
	//	B[i] = A[i];
	//for (int i = 0, j = 0, r = 0; (i < lb) || (j < lc);)
	//{
	//	if ((i < lb) && (!(j < lc) || (B[i] <= C[j])))
	//	{
	//		A[r++] = B[i++]; cout << A[r - 1] << "  ";
	//	}
	//	if ((j < lc) && ((!(i < lb)) || (C[j] < B[i])))
	//	{
	//		A[r++] = C[j++]; cout << A[r - 1] << "  ";
	//	}
	//}cout << endl;
	//delete[] B;
}
