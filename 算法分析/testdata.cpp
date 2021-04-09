#include "testdata.h"
#include <cstdlib>

//constexpr auto array_length = 100;

testdata::testdata(int length ) //构造函数形参名不要与成员变量相同，否则虽然实参能传递进来，但this所指向的成员仍然是初始化前的随机数，length不要超过1000
{
	len = length;
	setarray();
};

int testdata::getlen()
{
	return len;
};

void testdata::setarray()
{
	for (int i = 0; i < len; i++)
		array[i] = rand() % len;
};

int* testdata::getarray()
{
	return array;
}