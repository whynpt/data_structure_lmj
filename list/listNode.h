#pragma once

struct listNode
{
	int data;
	listNode* pred;
	listNode* succ;  //һ���̶��� pred��succ���Ա�ʾ�ڵ㱾���λ��
	listNode();
	listNode(int e, listNode* p, listNode* s);
	listNode* inserAsPred(int const &e);  //�ڸýڵ�ǰ�����½ڵ�
	listNode* inserAsSucc(int const &e);  // �ڸýڵ������½ڵ�
};