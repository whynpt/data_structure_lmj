#include"list.h"
#include<iostream>
using namespace std;

//header和trailer只是两个指针，需要把它们联系在一起
//从外部看，列表的header和trailer是私有成员，不可见视为NULL
//但从内部看，两者是listNode型的指针，需要有自己的空间
void list::init()  
{
	//listNode* header;  只是一个声明，，未初始化
	header = new listNode;
	trailer = new listNode;
	header->succ = trailer;
	trailer->succ = header;
	header->pred = NULL;
	trailer->succ = NULL;
}

void list::clear()
{

}

list::list()
{
	init();
}

list::list(list const& L)
{
	_size = size();
	header = 
}

int list::size()
{
	return _size;
}