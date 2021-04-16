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
	list(list const& L);  //整体复制列表
	list(list const& L, int r, int n);  //复制列表的第r项起的n项数据
	list(list const& L, listNode* p, int n);  //复制列表的从位置p起的n项数据
	~list();
	int size();

private:
	int _size;
	listNode* header;
	listNode* trailer;
};
