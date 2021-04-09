#pragma once
//注意递归过程中是否用到了返回值
//使用math的pow函数，会有double到int转换的警告

inline int sqr(int num) { return num * num; }
int power2(int n)
{
	if (n == 0) return 1;
	return (n % 2)? sqr(power2(n / 2)) * 2: sqr(power2(n / 2)) ;

}