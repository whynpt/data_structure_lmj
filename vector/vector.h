#pragma once
#include<iostream>
#define DEFAULT_CAPACITY  3 //Ĭ������
typedef int Rank;
template<typename T>  //���ⶨ���Ա����ʱ,ÿ������ǰ��Ҫ����仰,��ʹ���ڱ��ļ���

class vector
{
private:
	Rank _size; // ��ǰԪ�ظ���
	int _capacity;  // ��ǰ������С
	T* _elem;  // �������׵�ַ
	void copyFrom(T const* A, Rank start, Rank end);  //���ƺ���,����ҿ�
	void expand(); //�ռ䲻��ʱ����
	void shrink(); //װ�����ӹ�Сʱѹ��
public:
	//���캯��
	vector(int c = DEFAULT_CAPACITY, Rank s = 0, T v = 0);  //��ʼ��Ϊ0�Ĺ��캯��
	vector(T const* A, Rank n); //�������帴��, T���������β�
	vector(T const* A, Rank start, Rank end); //�������临��
	vector(vector<T> const& V); //�������帴��, vector�������β�
	vector(vector<T> const& V, Rank start, Rank end); //�������临��
	//��������
	~vector() { delete [] _elem; } //��������
	//ֻ���ӿ�
	Rank size() const ; // ����Ԫ�ظ���
	Rank find(T const e); //������������
	Rank find(T const e, Rank start, Rank end); //��������������ң����ص�һ����ͬԪ�ص���
	Rank search(T const e); // ������������
	Rank search(T const e, Rank start, Rank end);  // ��������������ң����ص�һ����ͬԪ�ص���
	ostream operator << (vector<T> const& V);  //����<<���������
	//��д���ʽӿ�
	void TooLong(); //�ж��Ƿ�װ��̫С
	void TooShort();  // �ж��Ƿ�װ��̫��
	T& operator[] (Rank r);  //  ���ز��������Ա����Ԫ��
	const T& operator[] (Rank r) const;  //  ����ֵ�����Ըı䣬������ֵ
	//vector<T>& operator= (vector<T> const & V, Rank start, Rank end);  //���丳ֵ������  �޷�ʶ��Ϊ���Ա���д����
	Rank remove(Rank r); //ɾ����Ϊr��Ԫ��
	int remove(Rank start, Rank end);  //ɾ�������ڵ�Ԫ��
	Rank insert(T const& e, Rank r); // ��Ԫ��e������r��
	Rank insert(T const& e);  //��Ԫ����ĩβ����
	int deduplicate(); // ����ȥ��
	//int uniquify(); //����ȥ��
};

