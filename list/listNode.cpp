#include"listNode.h"
#include<iostream>
using namespace std;

listNode::listNode(int e, listNode* p = NULL, listNode* s = NULL)
{
	data = e;
	pred = p;
	succ = s;
}

listNode::listNode()
{}

listNode* listNode::inserAsPred(int const& e)
{
	listNode* newNode = new listNode(e, pred, this);
	pred->succ = newNode;
	pred = newNode;
	return newNode;
}

listNode* listNode::inserAsSucc(int const& e)
{
	listNode* newNode = new listNode(e, this, succ);
	succ->pred = newNode;
	succ = newNode;  //此两句顺序不可颠倒
	return newNode;
}