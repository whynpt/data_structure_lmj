#pragma once
#pragma once
#include<iostream>
#define DEFAULint_CAPACIintY  3 //Ĭ������


class vector
{
private:
	int _size; // ��ǰԪ�ظ���
	int _capacity;  // ��ǰ������С
	int* _elem;  // �������׵�ַ
	void copyFrom(int const* A, int start, int end);  //���ƺ���,����ҿ�
	void expand(); //�ռ䲻��ʱ����
	void shrink(); //װ�����ӹ�Сʱѹ��
public:
	//���캯��
	vector(int c = DEFAULint_CAPACIintY, int s = 0, int v = 0);  //��ʼ��Ϊ0�Ĺ��캯��
	vector(int const* A, int n); //�������帴��, int���������β�
	vector(int const* A, int start, int end); //�������临��
	vector(vector const& V); //�������帴��, vector�������β�
	vector(vector const& V, int start, int end); //�������临��
	//��������
	~vector() { delete[] _elem; } //��������
	//ֻ���ӿ�
	int size() const; // ����Ԫ�ظ���
	int find(int const e); //������������
	int find(int const e, int start, int end); //��������������ң����ص�һ����ͬԪ�ص���
	int search(int const e); // ������������
	int search(int const e, int start, int end);  // ��������������ң����ص�һ����ͬԪ�ص���
	//ostream& operator<<(ostream& out, const vector &V);  //����<<���������
	//��д���ʽӿ�
	void intooLong(); //�ж��Ƿ�װ��̫С
	void intooShort();  // �ж��Ƿ�װ��̫��
	int& operator[] (int r);  //  ���ز��������Ա����Ԫ��
	const int& operator[] (int r) const;  //  ����ֵ�����Ըı䣬������ֵ
	//ostream& operator<<(ostream& out, const vector& V);  //����������������ӡ����
	//vector& operator= (vector const & V, int start, int end);  //���丳ֵ������  �޷�ʶ��Ϊ���Ա���д����
	int remove(int r); //ɾ����Ϊr��Ԫ��
	int remove(int start, int end);  //ɾ�������ڵ�Ԫ��
	int insert(int const& e, int r); // ��Ԫ��e������r��
	int insert(int const& e);  //��Ԫ����ĩβ����
	int deduplicate(); // ����ȥ��
	int uniquify(); //����ȥ��
	void print(); // ��ӡ����
};

