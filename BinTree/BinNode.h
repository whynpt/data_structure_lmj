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
	//int size();  // �Ըýڵ�Ϊ���������Ľڵ���
	BinNode* inserAsLc(int const&);  // �½��ýڵ������
	BinNode* inserAsRc(int const&);  // �½��ýڵ���Һ���
	BinNode* succ();  //ȡ�ڵ��ֱ�Ӻ��
	bool operator< (BinNode const& bn);  // �Ƚ����ݴ�С
	bool operator== (BinNode const& bn); 
	bool isRoot();
	bool isLc();  // �жϽڵ��ǲ�������
	bool isRc();
};

