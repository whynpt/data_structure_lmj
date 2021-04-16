#pragma once
#include"listNode.h"

class list
{
protected:
	void init();
	void clear();
	void copyNodes(listNode*, int);
	void mergeSort();
	void selectionSort();
	void insertionSort();

public:
	list();
	list(list const& L);  //���帴���б�
	list(list const& L, int r, int n);  //�����б�ĵ�r�����n������
	list(list const& L, listNode* p, int n);  //�����б�Ĵ�λ��p���n������
	~list();
	int size();

private:
	int _size;
	listNode* header;
	listNode* trailer;
};
