#pragma once
// O(log n)
//�Ľ��������while(n>0)���� n & n-1 �Ĵ�����������һ�ĸ����� O(ones)  
int countOnes(int num)
{
	int count = 0, tmp = num, biNum = 0;
	while (tmp)
	{
		if (tmp % 2)
		{
			count++;
			biNum = biNum * 10 + 1;
		}
		tmp = tmp >> 1;
	}
	printf("num %d equals (%d), %d ones \n", num, biNum, count);
	return 0;
}