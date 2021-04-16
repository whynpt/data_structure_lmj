#pragma once

struct listNode
{
	int data;
	listNode* pred;
	listNode* succ;  //一定程度上 pred和succ可以表示节点本身的位置
	listNode();
	listNode(int e, listNode* p, listNode* s);
	listNode* inserAsPred(int const &e);  //在该节点前插入新节点
	listNode* inserAsSucc(int const &e);  // 在该节点后插入新节点
};