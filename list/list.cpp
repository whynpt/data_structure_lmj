#include"list.h"
#include<iostream>
using namespace std;

//函数体多加const修饰，不然有时会出现C++ 对象含有与成员 函数 不兼容的类型限定符
//header和trailer只是两个指针，需要把它们联系在一起
//从外部看，列表的header和trailer是私有成员，不可见视为NULL
//但从内部看，两者是listNode型的指针，需要有自己的空间
void list::init()  
{
	//listNode* header;  只是一个声明，，未初始化
	header = new listNode;
	trailer = new listNode;
	header->succ = trailer;
	trailer->pred = header;
	header->pred = NULL;
	trailer->succ = NULL;
}


void list::copyNodes(listNode* p, int n)
{
	init();  // 新建一个空列表
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
	return e;  //指针已删除，不能使用p->data
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
	cout << "元素个数：" << s << endl;
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

listNode* list::find(int const& e, listNode* p, int n)  //找到最左边相同的值
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
	header = tmp;  //两者换名字，全改为反转后的列表成员名称
	q = p->pred;
	while (s--) // q不为NULL，即迭代后p不为反转后列表的trailer
	{
		p->pred = tmp;
		p->succ = q;  //修改当前节点的前驱后继
		tmp = p;
		p = p->succ;
		q = q->pred;  //迭代完之后q第二次变为first(),所以修改while的结束条件，不依靠q的位置判断
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
