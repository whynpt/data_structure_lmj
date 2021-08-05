#include"BinTree.h"

BinTree::BinTree(int e = 0, BinNode* p = nullptr)  //构造一个空树
{
	_size = e;
	_root = p;
}

int BinTree::size()
{
	return _size;
}

bool BinTree::empty()
{
	return !_root;
}

BinNode* BinTree::root()
{
	return _root;
}

BinNode* BinTree::insertAsRoot(int const e)
{
	_root = new BinNode(e);
	return _root;
}

BinNode* BinTree::insertAsLC(BinNode* x, int const e)
{
	x->lc = new BinNode(e);
	_size++;
	return x->lc;
}

BinNode* BinTree::insertAsRC(BinNode* x, int const e)
{
	x->rc = new BinNode(e);
	_size++;
	return x->rc;
}

BinNode* BinTree::attachAsLC(BinNode* p, BinTree* c)
{
	p->lc = c->_root;
	_size += c->size();
	return p->lc;
}

BinNode* BinTree::attachAsRC(BinNode* p, BinTree* c)
{
	p->rc = c->_root;
	_size += c->size();
	return p->rc;
}

void BinTree::remove(BinNode x)
{
	if (x.isLc())
	{
		x.parent->lc = nullptr;
		_size -= x.size();
	}

}
