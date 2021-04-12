#include"vector.h"
#include<iostream>
using namespace std;
typedef int Rank;

//默认构造函数
template<typename T>
vector<T> ::vector(int c, Rank s, T v)
{
	_elem = new T[_capacity = 2 * c];
	for (_size = 0; _size < s; _elem[_size++] = v); 
		//_elem[_size] = v;
};

//数组整体复制
template<typename T>
vector<T> ::vector(T const* A, Rank n)
{
	_elem = new T[_capacity = n];
	copyFrom(A, 0, n);
}

//数组区间复制
template<typename T>
vector<T> ::vector(T const* A, Rank start, Rank end)
{
	copyFrom(A, start, end);
}

//向量整体复制
template<typename T>
vector<T> ::vector(vector<T> const& V)
{
	copyFrom(V._elem, 0, V._size);
}

//数组区间复制
template<typename T>
vector<T> ::vector(vector<T> const& V, Rank start, Rank end)
{
	copyFrom(V._elem, start, end);
}

//复制函数
template<typename T>
void vector<T>::copyFrom(T const* A, Rank start, Rank end)
{
	_elem = new T[ _capacity = 2 * ( end - start) ];  
	for (_size = 0; start < end; _size++, start++)
	{
		_elem[_size] = A[start];
	}
};

//读取元素个数
template<typename T>
Rank vector<T>::size() const 
{ return _size; }

//无序整体查找
template<typename T>
Rank vector<T>::find(T const e)
{
	return find(e, 0, size());
}

//无序区间查找
template<typename T>
Rank vector<T>::find(T const e, Rank start, Rank end)
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
template<typename T>
Rank vector<T>::search(T const e)
{
	search(e, 0, size());
}

//有序区间查找
template<typename T>
Rank vector<T>::search(T const e, Rank start, Rank end)
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
template<typename T>
void vector<T>::expand()
{
	T * newelem = new T[_capacity = _capacity * 2];
	for (int i = 0; i < _size; i++)
	{
		newelem[i] = _elem[i];
	}
	delete[] _elem;
	_elem = newelem;

}

//缩容
template<typename T>
void vector<T>::shrink()
{
	T* newelem = new T[_capacity = _size * 2];
	for (int i = 0; i < _size; i++)
	{
		newelem[i] = _elem[i];
	}
	delete[] _elem;
	_elem = newelem;
}

template<typename T>
void vector<T>::TooLong()
{
	if (_capacity > _size * 2)
		shrink();
}

template<typename T>
void vector<T>::TooShort()
{
	if (_capacity <= _size * 2)
		expand();
}

//重载[]
template<typename T>
T& vector<T>::operator[] (Rank r)
{
	return _elem[r];
}

//重载[]
template<typename T>
const T& vector<T>::operator[] (Rank r) const
{
	return _elem[r];
}

//重载=
//template<typename T>
//vector<T>& vector<T>::operator= (vector<T> const& V, Rank start, Rank end)
//{
//	//T* newelem = new T [_capaci;
//}

//区间删除
template<typename T>
int vector<T>::remove(Rank start, Rank end)
{
	Rank tmp = end;  // 需移动元素的首下标
	while(start < tmp)
	_elem[start++] = _elem[end++];
	TooLong();  // 判断删除后的向量是否需要缩容
	_size -= (end - start); 					
	return _size;
}

//单个元素删除
template<typename T>
Rank vector<T>::remove(Rank r)
{	
	while ( r++ < _size)
		_elem[r] = _elem[r + 1];
	_size--;
	return _size;
}

//指定位置插入
template<typename T>
Rank vector<T>::insert(T const& e, Rank r)
{
	while (r < _size)
	{
		_elem[r + 1] = _elem[r];
	}
	_elem[r] = e;
	
	return ++_size;
}

//末尾插入
template<typename T>
Rank vector<T>::insert(T const& e)
{
	insert(e, _size);
	return ++_size;

}

//无序去重
template<typename T>
int vector<T>::deduplicate()
{
	for (int i = 0; i < _size; i++)
		for(int j = 0; j < _size;j++ )
		{
			if (_elem[i] == _elem[j] && i != j)
				remove(i);
				_size--;
		}
	return _size;
}

template<typename T>
int vector<T>::uniquify()
{
	int start = 0;
	for (Rank r = 0; r < _size; r++)
	{
		if (_elem[r] != _elem[r + 1])
		{
			remove(start, r + 1);
			start = r + 1;
		}
	}
	return _size;
}

//打印向量
template<typename T>
void vector<T>::print()
{	

	Rank r = 0;
	while(r++ < _size)
	cout << _elem[r];
}

//打印向量
//template<typename T>
//ostream& vector<T>::operator<<(ostream& out, const vector<T>& V)
//{
//	for (Rank r = 0; r < _size; r++) out << V[r];
//	return out;
//};