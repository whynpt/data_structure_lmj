#include "testdata.h"
#include <cstdlib>

//constexpr auto array_length = 100;

testdata::testdata(int length ) //���캯���β�����Ҫ���Ա������ͬ��������Ȼʵ���ܴ��ݽ�������this��ָ��ĳ�Ա��Ȼ�ǳ�ʼ��ǰ���������length��Ҫ����1000
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