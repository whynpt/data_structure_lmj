#pragma once
#include"listNode.h"

class list
{
protected:
	void init();
	void clear();
	void copyNodes(listNode* p, int n);

public:
	list();
	list(list const& L);  //整体复制列表
	list(list const& L, int r, int n);  //复制列表的第r项起的n项数据
	list(listNode* p, int n);  //复制列表的从位置p起的n项数据
	listNode* insertAsFirst(int const& e);
	listNode* insertAsLast(int const& e);
	listNode* insertAsPred(listNode* p, int const& e);
	listNode* insertAsSucc(listNode* p, int const& e);
	~list() {};
	int size();
	bool empty () const;
	int& operator[] (int r) const;  // 返回第r个节点的值
	listNode* find(int const& e);  //无序查找
	listNode* find(int const& e, listNode* p, int n);  //无序区间查找
	//listNode* search(int const& e);  //有序查找  仍然是遍历，不写了
	listNode* selectMax(listNode* p, int n);  //从p开始的n个元素查找最大值
	listNode* selectMax();  //整体查找最大值
	int remove(listNode* p);  //删除p处节点
	//void sort(listNode* p, int n); // 区间排序
	//void sort(); // 整体排序
	int deduplicate();  //无序去重,返回删除元素的总数
	int uniquify();  //有序去重
	void reverse1();  //前后倒置
	void reverse2();  //前后倒置
	void reverse3();  //前后倒置
	listNode* first()const;  // 返回列表第一个节点位置
	listNode* last()const;  //  返回列表最后一个节点位置
	void print();  //打印列表值
private:
	int _size;
	listNode* header;
	listNode* trailer;
};
