#include "BinNode.h"

BinNode::BinNode()
{
	parent = nullptr;
	lc = nullptr;
	rc = nullptr;
	_height = 0;
}

BinNode::BinNode(int e, BinNode* parent, BinNode* lc, BinNode* rc, int h )
{
	data = e;
	parent = nullptr;
	lc = nullptr;
	rc = nullptr;
	h = 0;
}

//int BinNode::size()
//{
//	int size = 1;
//	if (lc) size += lc->size();  //->�ĳ�.�ᱨ�����ʽ�������������
//	if (rc) size += rc->size();
//	return size;
//}

BinNode* BinNode::inserAsLc(int const& e)  // ���ش���һ���½ڵ㣬ֱ�Ӵ���һ���ڵ�ָ��
{
	lc = new BinNode (e, this);
	BinNode* prt = this;
	return lc;
}

BinNode* BinNode::inserAsRc(int const& e)
{
	rc = new BinNode(e, this);
	return rc;
}

BinNode* BinNode::succ() // �������������
{
	BinNode* s = this;
	if (s->rc)  // ����������
	{
		s = s->rc;
		while (s->lc)
			s = s->lc;  //��������������ߵ�Ҷ�ӽڵ�
	}
	else  //û��������������this�ѱ����꣬Ҫ�ص�����û�з��ʵĽڵ�
	{
		 
		while(s->isRc())  //���Ϸ��أ��ж��Լ��ǲ������ӣ��ǵĻ����׾�û�з��ʣ�������Һ��Ӿ��ٷ���
			s = s->parent;
		s = s->parent;
	}
	return s;
}

bool BinNode::operator< (BinNode const& bn)
{
	return this->data < bn.data;
}

bool BinNode::operator== (BinNode const& bn)
{
	return this->data ==bn.data;
}

bool BinNode::isRoot()
{
	return !(this->parent);
}
bool BinNode::isLc()
{
	return (!this->isRoot()) && (this == (this->parent->lc));
}

bool BinNode::isRc()
{
	return (!this->isRoot()) && (this == (this->parent->rc));
}