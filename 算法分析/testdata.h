#pragma once
class testdata
{
private:
	int len;  // ���鳤��
	int array[1000] = { 0 };  // �������飬��ָ�����鳤�Ȼ�������ջ��, 
public:
	testdata(int len);
	int getlen();
	int* getarray();
	void setarray();
};

