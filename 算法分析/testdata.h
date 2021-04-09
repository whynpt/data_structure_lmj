#pragma once
class testdata
{
private:
	int len;  // 数组长度
	int array[1000] = { 0 };  // 整数数组，不指明数组长度会引发推栈损坏, 
public:
	testdata(int len);
	int getlen();
	int* getarray();
	void setarray();
};

