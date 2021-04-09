#pragma once
//2021/4/5 14点32分 新建fib.cpp，单步执行程序，跳转到next时，f、g不会暂时变为随机数

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
}  //这里的冒号可加可不加

