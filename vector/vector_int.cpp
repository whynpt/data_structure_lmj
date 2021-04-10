#include"vector_int.h"
#include<iostream>
using namespace std;


//Ĭ�Ϲ��캯��

vector ::vector(int c, int s, int v)
{
	_elem = new int[_capacity = 2 * c];
	for (_size = 0; _size < s; _elem[_size++] = v);
	//_elem[_size] = v;
};

//�������帴��

vector ::vector(int const* A, int n)
{
	_elem = new int[_capacity = n];
	copyFrom(A, 0, n);
}

//�������临��

vector ::vector(int const* A, int start, int end)
{
	copyFrom(A, start, end);
}

//�������帴��

vector ::vector(vector const& V)
{
	copyFrom(V._elem, 0, V._size);
}

//�������临��

vector ::vector(vector const& V, int start, int end)
{
	copyFrom(V._elem, start, end);
}

//���ƺ���

void vector::copyFrom(int const* A, int start, int end)
{
	_elem = new int[_capacity = 2 * (end - start)];
	for (_size = 0; start < end; _size++, start++)
	{
		_elem[_size] = A[start];
	}
};

//��ȡԪ�ظ���

int vector::size() const
{
	return _size;
}

//�����������

int vector::find(int const e)
{
	return find(e, 0, size());
}

//�����������

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

//�����������

int vector::search(int const e)
{
	return search(e, 0, size());
}

//�����������

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

//����

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

//����

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

//����[]

int& vector::operator[] (int r)
{
	return _elem[r];
}

//����[]

const int& vector::operator[] (int r) const
{
	return _elem[r];
}

//����<<
ostream& operator<<(ostream& out, const vector& V)
{
	for(int i = 0; i < V.size(); i++)
	out << V[i] << "  ";
	return out;
}

//����=
//
//vector& vector::operator= (vector const& V, int start, int end)
//{
//	//int* newelem = new int [_capaci;
//}

//����ɾ��

int vector::remove(int start, int end)
{
	int tmp = end;  // ���ƶ�Ԫ�ص����±�
	while (start < tmp)
		_elem[start++] = _elem[end++];
	intooLong();  // �ж�ɾ����������Ƿ���Ҫ����
	_size -= (end - start);
	return _size;
}

//����Ԫ��ɾ��

int vector::remove(int r)
{
	while (r++ < _size)
		_elem[r] = _elem[r + 1];
	_size--;
	return _size;
}

//ָ��λ�ò���

int vector::insert(int const& e, int r)
{
	while (r < _size)
	{
		_elem[r + 1] = _elem[r];
	}
	_elem[r] = e;

	return ++_size;
}

//ĩβ����

int vector::insert(int const& e)
{
	insert(e, _size);
	return ++_size;

}

//����ȥ��

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

//��ӡ����

void vector::print()
{
	int r = 0;
	while (r++ < _size)
		cout << _elem[r];
}

//��ӡ����
//
//ostream& vector::operator<<(ostream& out, const vector& V)
//{
//	for (int r = 0; r < _size; r++) out << V[r];
//	return out;
//};