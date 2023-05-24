#pragma once
#include<iostream>
#define DEFAULT_CAPACITY  3
typedef int Rank;
typedef int Size;

template<typename T> class MyVector
{
private:
    Size _size;
    int _capacity;
    T* _elem;  // addr of first element
    void copyFrom(T const* vec, Rank start, Rank end);  //copy from an existing vector, not include end
    void expand();
    void shrink();

public:
    // MyVector();
    MyVector(int c);
    // MyVector(int c = DEFAULT_CAPACITY, Size s = 0, T v = 0);
    MyVector(T const* vec, Size s);
    MyVector(T const* vec, Rank start, Rank end);
    MyVector(MyVector<T> const& V);
    MyVector(MyVector<T> const& V, Rank start, Rank end);
    ~MyVector() { delete [] _elem;}

    T* data();
    Size size() const;
    // find first element
    // find in unordered vector
    Rank find(T const e);
    Rank find(T const e, Rank start, Rank end);
    // search in ascending vector
    Rank search(T const e);
    Rank search(T const e, Rank start, Rank end);

    bool isTooLong();
    bool isTooShort();
    const T& operator[] (Rank r) const;  // the return value is const and data member can't be changed
    MyVector<T>& operator= (MyVector<T> const & V);
    // friend const std::ostream& operator<< (const std::ostream& os, const MyVector<T>& vec);
    Rank remove(Rank r);
    int remove(Rank start, Rank end);
    Rank insert(T const& e, Rank r);
    Rank insert(T const& e);
    int deduplicate();
    int uniquify();
};

