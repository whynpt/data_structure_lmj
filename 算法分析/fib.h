#pragma once
//2021/4/5 14��32�� �½�fib.cpp������ִ�г�����ת��nextʱ��f��g������ʱ��Ϊ�����

namespace fib
{
	class fib_
	{
	public:
		fib_(int n);
		int get();
		int next();
		int prev();
	private:
		int f, g;
	};
}  //�����ð�ſɼӿɲ���

