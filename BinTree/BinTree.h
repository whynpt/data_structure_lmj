#pragma once
#include"BinNode.h"

class BinTree
{
	int _size;
	BinNode* _root;
public:
	BinTree(int e, BinNode* p);
	//~BinTree(); ����
	int size();
	bool empty();
	BinNode* root();  // ���ظ��ڵ�
	BinNode* insertAsRoot(int const e);  //������ڵ�
	BinNode* insertAsLC(BinNode* x, int const e);  //�½�x������
	BinNode* insertAsRC(BinNode* x, int const e);
	BinNode* attachAsLC(BinNode* p, BinTree* c);  //��c��Ϊp������������
	BinNode* attachAsRC(BinNode* p, BinTree* c);
	void remove(BinNode x); // ɾ����xΪ��������
	void trLevel(); //��α���
	void trPre(); //�������
	void trIn(); //�������
	void trProst(); //�������
};
