#include"list.h"
#include<iostream>
using namespace std;

//header��trailerֻ������ָ�룬��Ҫ��������ϵ��һ��
//���ⲿ�����б��header��trailer��˽�г�Ա�����ɼ���ΪNULL
//�����ڲ�����������listNode�͵�ָ�룬��Ҫ���Լ��Ŀռ�
void list::init()  
{
	//listNode* header;  ֻ��һ����������δ��ʼ��
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