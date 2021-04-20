#include"list.h"
#include<iostream>
using namespace std;

//��������const���Σ���Ȼ��ʱ�����C++ ���������Ա ���� �����ݵ������޶���
//header��trailerֻ������ָ�룬��Ҫ��������ϵ��һ��
//���ⲿ�����б��header��trailer��˽�г�Ա�����ɼ���ΪNULL
//�����ڲ�����������listNode�͵�ָ�룬��Ҫ���Լ��Ŀռ�
void list::init()  
{
	//listNode* header;  ֻ��һ����������δ��ʼ��
	header = new listNode;
	trailer = new listNode;
	header->succ = trailer;
	trailer->pred = header;
	header->pred = NULL;
	trailer->succ = NULL;
}


void list::copyNodes(listNode* p, int n)
{
	init();  // �½�һ�����б�
	while (n--)
	{
		insertAsLast(p->data);
		p = p->succ;
	}
}

list::list()
{
	init();
}

list::list(list const& L)
{/*
	init();
	int i = L.size();
	whle(i--)
	{
		insertAsLast();
	}*/
	copyNodes(L.first(), L._size);
}

list::list(list const& L, int r, int n)
{
	listNode* p = L.first();
	while (r--)
		p = p->succ;
	copyNodes(p, n);
}

list::list(listNode* p, int n)
{
	copyNodes(p, n);
}

int list::size()
{
	return _size;
}

listNode* list::insertAsFirst(int const& e)
{
	header->inserAsSucc(e);
	_size++;
	return header;
}

listNode* list::insertAsLast(int const& e)
{
	trailer->inserAsPred(e);
	_size++;
	return trailer;
}

listNode* list::insertAsPred(listNode* p, int const& e)
{
	p->inserAsPred(e);
	_size++;
	return 0;
}

listNode* list::insertAsSucc(listNode* p, int const& e)
{
	p->inserAsSucc(e);
	_size++;
	return 0;
}

int list::remove(listNode* p)
{
	int e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;  //ָ����ɾ��������ʹ��p->data
}

void list::clear()
{
	while (_size)
		remove(header->succ);
}

listNode* list::first()const
{
	return header->succ;
}

listNode* list::last()const
{
	return trailer->pred;
}

int& list::operator[](int r) const
{
	listNode* p = header;
	while (r--)
		p = p->succ;
	return p->data;
}

void list::print()
{

	int s = _size;
	listNode* p = header->succ;
	cout << "Ԫ�ظ�����" << s << endl;
	cout << "header-->";
	while (s--)
	{
		cout << p->data << "-->";
		p = p->succ;
	}
	cout << "trailer"<<endl;
}

listNode* list::find(int const& e)
{
	return find(e, header->succ, _size);
}

listNode* list::find(int const& e, listNode* p, int n)  //�ҵ��������ͬ��ֵ
{
	while (n--)
	{		
		if (e == p->data)
			return p;
		p = p->succ;
	}
	return NULL;
}

bool list::empty ()const
{
	if (_size == 0)
		return true;
	else
		return false;
	//return _size ? false : true;
}

listNode* list::selectMax(listNode* p, int n)
{
	listNode* m = p;
	int max = p->data;
	while (n-- > 1)
	{
		p = p->succ;
		if (max < p->data)
		{
			max = p->data;
			m = p;
		}
		
	}	
	return m;
}

listNode* list::selectMax()
{
	return selectMax(header->succ, _size);
}


int list::deduplicate()
{
	listNode* first = header->succ;
	listNode* p = header->succ;
	int oldsize = _size;
	for (int r = 1; r < _size - 1; r++)
	{
		p = p->succ;
		listNode* p1 = find(p->data, first, r);
		if (p1)
		{
			remove(p1);
			r--;
		}
	}
	return oldsize - _size;
}

int list::uniquify()
{
	int oldsize = _size;
	listNode* p = header->succ;
	listNode* q;
	while ((q = p->succ)!= trailer)
	{
		if (p->data == q->data)
			remove(q);
		else
			p = q;
	}
	return oldsize - _size;
}

void list::reverse1()
{
	listNode* tmp, *p = last(), *q = first();
	int s = _size;
	trailer->succ = p;
	trailer->pred = NULL;
	header->pred = q;
	header->succ = NULL;
	tmp = trailer;
	trailer = header;
	header = tmp;  //���߻����֣�ȫ��Ϊ��ת����б��Ա����
	q = p->pred;
	while (s--) // q��ΪNULL����������p��Ϊ��ת���б��trailer
	{
		p->pred = tmp;
		p->succ = q;  //�޸ĵ�ǰ�ڵ��ǰ�����
		tmp = p;
		p = p->succ;
		q = q->pred;  //������֮��q�ڶ��α�Ϊfirst(),�����޸�while�Ľ���������������q��λ���ж�
	}
}

void list::reverse2()
{
	listNode* p = first(), * q = last();
	int tmp;
	while (p != q)
	{
		swap(p->data, q->data);
		p = p->succ;
		q = q->pred;
	}
}

void list::reverse3()
{
	for (listNode* p = header, *q = p->succ; p != trailer; p = q, q = q->succ)
		p->pred = q;
	trailer->pred = NULL;
	for (listNode* p = header, *q = p->pred; p != trailer; p = q, q = q->pred)
		q->succ = p;
	header->succ = NULL;
	swap(header, trailer);
}
