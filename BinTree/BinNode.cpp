#include "BinNode.h"

BinNode::BinNode()
{
	parent = nullptr;
	lc = nullptr;
	rc = nullptr;
}

BinNode::BinNode(int e, BinNode* parent, BinNode* lc, BinNode* rc, int h )
{
	data = e;
	parent = nullptr;
	lc = nullptr;
	rc = nullptr;
	h = 0;
}

//int BinNode::size(BinNode* root)
//{
//	if (!root) return 0;
//	return size(root -> lc) + size(root -> rc) + 1;;
//}
//
//BinNode* BinNode::inserAsLc(int const& e)  // 不必创建一个新节点，直接创建一个节点指针
//{
//	lc = new BinNode (e, this);
//	BinNode* prt = this;
//	return lc;
//}
//
//BinNode* BinNode::inserAsRc(int const& e)
//{
//	rc = new BinNode(e, this);
//	return rc;
//}

BinNode* BinNode::succ() // 仅限于中序遍历
{
	BinNode* s = this;
	if (s->rc)  // 进入右子树
	{
		s = s->rc;
		while (s->lc)
			s = s->lc;  //到达右子树最左边的叶子节点
	}
	else  //没有右子树，则树this已遍历完，要回到上面没有访问的节点
	{
		 
		while(s->isRc())  //向上返回，判断自己是不是左孩子，是的话父亲就没有访问，如果是右孩子就再返回
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