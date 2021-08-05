#pragma once
struct BinNode
{
	friend class BinTree;
public:
	int data;
	BinNode* parent, *lc, *rc;
	//int _height;
	BinNode();
	BinNode(int e, BinNode* parent = nullptr, BinNode* lc = nullptr, BinNode* rc = nullptr, int h = 0);
	//int size();  // 以该节点为根的子树的节点数
	BinNode* inserAsLc(int const&);  // 新建该节点的左孩子
	BinNode* inserAsRc(int const&);  // 新建该节点的右孩子
	BinNode* succ();  //取节点的直接后继
	bool operator< (BinNode const& bn);  // 比较数据大小
	bool operator== (BinNode const& bn); 
	bool isRoot();
	bool isLc();  // 判断节点是不是左孩子
	bool isRc();
};

