#include"fib.h"

namespace fib {
	fib_::fib_(int n)
	{
		f = 1;
		g = 0;
		while (g < n)
			next();
	}

	int fib_::get()
	{
		return g;
	}

	int fib_::next()
	{
		g += f;
		f = g - f;
		return g;
	}

	int fib_::prev()
	{
		f = g - f;
		g = g - f;
		return g;
	}
}   //这里的冒号可加可不加
