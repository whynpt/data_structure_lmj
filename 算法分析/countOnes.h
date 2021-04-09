#pragma once
// O(log n)
//改进版可以用while(n>0)计算 n & n-1 的次数，次数即一的个数。 O(ones)  
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