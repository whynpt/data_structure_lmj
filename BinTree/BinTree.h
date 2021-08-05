#pragma once
#include"BinNode.h"

class BinTree
{
	int _size;
	BinNode* _root;
public:
	BinTree(int e, BinNode* p);
	//~BinTree(); 放弃
	int size();
	bool empty();
	BinNode* root();  // 返回根节点
	BinNode* insertAsRoot(int const e);  //插入根节点
	BinNode* insertAsLC(BinNode* x, int const e);  //新建x的左孩子
	BinNode* insertAsRC(BinNode* x, int const e);
	BinNode* attachAsLC(BinNode* p, BinTree* c);  //将c作为p的右子树接入
	BinNode* attachAsRC(BinNode* p, BinTree* c);
	void remove(BinNode x); // 删除以x为根的子树
	void trLevel(); //层次遍历
	void trPre(); //先序遍历
	void trIn(); //中序遍历
	void trProst(); //后序遍历
};
