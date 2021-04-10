#pragma once
#pragma once
#include<iostream>
#define DEFAULint_CAPACIintY  3 //默认容量


class vector
{
private:
	int _size; // 当前元素个数
	int _capacity;  // 当前容量大小
	int* _elem;  // 数据区首地址
	void copyFrom(int const* A, int start, int end);  //复制函数,左闭右开
	void expand(); //空间不足时扩容
	void shrink(); //装填因子过小时压缩
public:
	//构造函数
	vector(int c = DEFAULint_CAPACIintY, int s = 0, int v = 0);  //初始化为0的构造函数
	vector(int const* A, int n); //数组整体复制, int型数组做形参
	vector(int const* A, int start, int end); //数组区间复制
	vector(vector const& V); //向量整体复制, vector类型做形参
	vector(vector const& V, int start, int end); //向量区间复制
	//析构函数
	~vector() { delete[] _elem; } //析构函数
	//只读接口
	int size() const; // 查找元素个数
	int find(int const e); //无序向量查找
	int find(int const e, int start, int end); //无序向量区间查找，返回第一个相同元素的秩
	int search(int const e); // 有序向量查找
	int search(int const e, int start, int end);  // 有序向量区间查找，返回第一个相同元素的秩
	//ostream& operator<<(ostream& out, const vector &V);  //重载<<，输出向量
	//可写访问接口
	void intooLong(); //判断是否装填太小
	void intooShort();  // 判断是否装填太大
	int& operator[] (int r);  //  重载操作符，以便访问元素
	const int& operator[] (int r) const;  //  返回值不可以改变，仅作右值
	//ostream& operator<<(ostream& out, const vector& V);  //重载输出运算符，打印向量
	//vector& operator= (vector const & V, int start, int end);  //区间赋值操作符  无法识别为类成员，有待解决
	int remove(int r); //删除秩为r的元素
	int remove(int start, int end);  //删除区间内的元素
	int insert(int const& e, int r); // 将元素e插入在r中
	int insert(int const& e);  //将元素在末尾插入
	int deduplicate(); // 无序去重
	int uniquify(); //有序去重
	void print(); // 打印向量
};

