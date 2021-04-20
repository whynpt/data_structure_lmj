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
	list(list const& L);  //���帴���б�
	list(list const& L, int r, int n);  //�����б�ĵ�r�����n������
	list(listNode* p, int n);  //�����б�Ĵ�λ��p���n������
	listNode* insertAsFirst(int const& e);
	listNode* insertAsLast(int const& e);
	listNode* insertAsPred(listNode* p, int const& e);
	listNode* insertAsSucc(listNode* p, int const& e);
	~list() {};
	int size();
	bool empty () const;
	int& operator[] (int r) const;  // ���ص�r���ڵ��ֵ
	listNode* find(int const& e);  //�������
	listNode* find(int const& e, listNode* p, int n);  //�����������
	//listNode* search(int const& e);  //�������  ��Ȼ�Ǳ�������д��
	listNode* selectMax(listNode* p, int n);  //��p��ʼ��n��Ԫ�ز������ֵ
	listNode* selectMax();  //����������ֵ
	int remove(listNode* p);  //ɾ��p���ڵ�
	//void sort(listNode* p, int n); // ��������
	//void sort(); // ��������
	int deduplicate();  //����ȥ��,����ɾ��Ԫ�ص�����
	int uniquify();  //����ȥ��
	void reverse1();  //ǰ����
	void reverse2();  //ǰ����
	void reverse3();  //ǰ����
	listNode* first()const;  // �����б��һ���ڵ�λ��
	listNode* last()const;  //  �����б����һ���ڵ�λ��
	void print();  //��ӡ�б�ֵ
private:
	int _size;
	listNode* header;
	listNode* trailer;
};
