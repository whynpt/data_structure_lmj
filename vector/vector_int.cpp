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


void vector::intooLong()
{
	if (_capacity > _size * 2)
		shrink();
}


void vector::intooShort()
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
ostream& operator<<(ostream& out, const vector& V)
{
	for(int i = 0; i < V.size(); i++)
	out << V[i] << "  ";
	return out;
}

//重载=
//
//vector& vector::operator= (vector const& V, int start, int end)
//{
//	//int* newelem = new int [_capaci;
//}

//区间删除

int vector::remove(int start, int end)
{
	int tmp = end;  // 需移动元素的首下标
	while (start < tmp)
		_elem[start++] = _elem[end++];
	intooLong();  // 判断删除后的向量是否需要缩容
	_size -= (end - start);
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

int vector::insert(int const& e, int r)
{
	while (r < _size)
	{
		_elem[r + 1] = _elem[r];
	}
	_elem[r] = e;

	return ++_size;
}

//末尾插入

int vector::insert(int const& e)
{
	insert(e, _size);
	return ++_size;

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


int vector::uniquify()
{
	int start = 0;
	for (int r = 0; r < _size; r++)
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

void vector::print()
{
	int r = 0;
	while (r++ < _size)
		cout << _elem[r];
}

//打印向量
//
//ostream& vector::operator<<(ostream& out, const vector& V)
//{
//	for (int r = 0; r < _size; r++) out << V[r];
//	return out;
//};