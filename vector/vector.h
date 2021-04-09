#pragma once
#include<iostream>
#define DEFAULT_CAPACITY  3 //默认容量
typedef int Rank;
template<typename T>  //类外定义成员函数时,每个函数前都要加这句话,即使是在本文件中

class vector
{
private:
	Rank _size; // 当前元素个数
	int _capacity;  // 当前容量大小
	T* _elem;  // 数据区首地址
	void copyFrom(T const* A, Rank start, Rank end);  //复制函数,左闭右开
	void expand(); //空间不足时扩容
	void shrink(); //装填因子过小时压缩
public:
	//构造函数
	vector(int c = DEFAULT_CAPACITY, Rank s = 0, T v = 0);  //初始化为0的构造函数
	vector(T const* A, Rank n); //数组整体复制, T型数组做形参
	vector(T const* A, Rank start, Rank end); //数组区间复制
	vector(vector<T> const& V); //向量整体复制, vector类型做形参
	vector(vector<T> const& V, Rank start, Rank end); //向量区间复制
	//析构函数
	~vector() { delete [] _elem; } //析构函数
	//只读接口
	Rank size() const ; // 查找元素个数
	Rank find(T const e); //无序向量查找
	Rank find(T const e, Rank start, Rank end); //无序向量区间查找，返回第一个相同元素的秩
	Rank search(T const e); // 有序向量查找
	Rank search(T const e, Rank start, Rank end);  // 有序向量区间查找，返回第一个相同元素的秩
	ostream operator << (vector<T> const& V);  //重载<<，输出向量
	//可写访问接口
	void TooLong(); //判断是否装填太小
	void TooShort();  // 判断是否装填太大
	T& operator[] (Rank r);  //  重载操作符，以便访问元素
	const T& operator[] (Rank r) const;  //  返回值不可以改变，仅作右值
	//vector<T>& operator= (vector<T> const & V, Rank start, Rank end);  //区间赋值操作符  无法识别为类成员，有待解决
	Rank remove(Rank r); //删除秩为r的元素
	int remove(Rank start, Rank end);  //删除区间内的元素
	Rank insert(T const& e, Rank r); // 将元素e插入在r中
	Rank insert(T const& e);  //将元素在末尾插入
	int deduplicate(); // 无序去重
	//int uniquify(); //有序去重
};

