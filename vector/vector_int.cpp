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
//ostream& operator<<(ostream& out, const vector& V)
//{
//	for(int i = 0; i < V.size(); i++)
//	out << V[i] << "  ";
//	return out;
//}

//����=
//vector& operator= (vector const& V, int start, int end)
//{
//	//int* newelem = new int [_capaci;
//}

//����ɾ��

int vector::remove(int start, int end)
{
	int tmp = end;  // ���ƶ�Ԫ�ص����±�
	while (end < _size)
		_elem[start++] = _elem[end++];
	_size -= (end - start);
	TooLong();  // �ж�ɾ����������Ƿ���Ҫ����
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

int vector::insert(int const& e, int r)   //�Ƚ��������λ�� �ٲ�����Ԫ��
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

//ĩβ����

int vector::insert(int const& e)
{
	insert(e, _size);
	return _size;

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

//����ȥ��
int vector::uniquify()
{
	int start = 0, num2remove;  //  num2remove��ĳ��ȥ����Ҫɾ����Ԫ����
	for (int r = 0; r < _size - 1; r++)
	{
		if ((_elem[r] != _elem[r + 1]) && (start < r))  // r + 1����Ԫ�ص���㣬������������಻С��2�� start + 2 <= r + 1�������ظ�Ԫ��
		{	
			remove(start + 1, r + 1);
			num2remove = r - start;
			start++; // ��Ԫ�ؼ�һ
			r = start;
		}
		print();
	}
	if(start != _size - 1)
		remove(start + 1, _size);
	return _size;
}

//��ӡ����
void vector::print()
{
	cout << "������" << _capacity << "\nԪ�ظ�����" << _size<< endl;
	int r = 0;
	while (r < _size)
	{
		cout << _elem[r] << "  ";
		r++;
	}
	cout<<endl;
}

//����
void vector::sort(int start, int end)
{
	switch (rand() % 2)
	{	
		case 1:mergeSort(start , end); break;
		default:  bubbleSort(start, end); break;
	}

}

//��������
void vector::bubbleSort(int start, int end) //����������ѭ�����������Ƿ����ɨ�裬�ڲ��������ɨ��
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
	while(end > start)
	{
		for (int j = start; j < end -1; j++)
		{
			last = 0;  // û�������Ҳ����lastΪ��λ��
			if (_elem[j + 1] < _elem[j])
			{
				swap(_elem[j + 1], _elem[j]);
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
	//		if (_elem[j + 1] < _elem[j])
	//		{
	//			ordered = false,
	//				swap(_elem[j + 1], _elem[j]);
	//		} 
	//		count++;
	//	}
	//�汾A
	//for (int i = start; i < end; i++)
	//	for (int j = start; j < end - i - 1; j++)
	//	{
	//		if (_elem[j + 1] < _elem[j])
	//			swap(_elem[j + 1], _elem[j]);
	//		count++;
	//	}
	cout << "�Ƚϴ���" << count << endl;
}

//�鲢����
void vector::mergeSort(int start, int end)
{
	if (end - start < 2)  //ֻ����ֹ��������mergeSort�����᲻����merge
		return;
	int mid = (start + end) >> 1;
	mergeSort(start, mid);
	mergeSort(mid, end);
	merge(start, mid, end);	//ÿ�ε��øú���������������������������ʵ�±꣬��һ�޶�

}

//�����鲢
void vector::merge(int start, int mid, int end)  //����_elem,��Ϊ����������ԭʼ������merge����ֻ�ǶԲ����������в��������û��޸���������������
{
	int lenL = mid - start, lenR = end - mid;
	int* left = new int[lenL];  //�������ڴ棬������벿�����������������д��Ż�
	for (int j = 0, i = start; i < mid; i++, j++)  // ���ܴ�0 ��ʼ��ֵ��Ҫע�⵱ǰ����
		left[j] = _elem[i];
	int* right = _elem + mid;  //ʵ���ϲ鿴�ڴ棬��һ�ν���ú������Կ���ԭ�������Ԫ�ظ�����left�������ĸ�����right
	int l = 0, r = 0;
	while (lenL > 0 && lenR > 0) // ���left��right������
	{
		if (left[l] > right[r])  // ��С�߽���ԭ����
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
