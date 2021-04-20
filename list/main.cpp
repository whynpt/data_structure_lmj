#include<iostream>
#include"list.h"
#include"listNode.h"

using namespace std;
int dice(int range) { return rand() % range; }
int main()
{
	list L, sortedL;
	for (int i = 0; i < 20; i++)
		L.insertAsFirst(dice(15));
	for (int i = 0; i < 20; i++)
		if(i%4 == 0)
			sortedL.insertAsFirst(i+1);
		else
			sortedL.insertAsFirst(i);
	L.print();
	L.insertAsLast(20);
	L.print();
 	L.insertAsPred(L.first()->succ, 21);
	L.print();
	L.insertAsSucc(L.first()->succ, 22);
	L.print();
	printf("第%d个节点是%d\n", 3, L[3]);
	listNode* p = L.find(2, L.first(), 5);
	if(p != NULL)cout << p->data << endl;
	L.reverse3();
	L.print();
	L.deduplicate();
	L.print();
	cout<<L.selectMax()->data<<endl;
	sortedL.print();
	sortedL.uniquify();
	sortedL.print();
	return 0;
}