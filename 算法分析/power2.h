#pragma once
//ע��ݹ�������Ƿ��õ��˷���ֵ
//ʹ��math��pow����������double��intת���ľ���

inline int sqr(int num) { return num * num; }
int power2(int n)
{
	if (n == 0) return 1;
	return (n % 2)? sqr(power2(n / 2)) * 2: sqr(power2(n / 2)) ;

}