#include"hanoi.h"
#include<iostream>

void hanoi(int n, int count = 1)  //������
{
	if (n > 0)
	{
		count = count * 2 + 1;
		hanoi(n - 1, count);
		printf("n : %d     %d\n", n, count);
	}
}
	