#include "MyVector.h"
#include <iostream>
#include <memory>

template<typename T>
void MyVector<T>::copyFrom(T const* A, Rank start, Rank end) {
    _elem = new T[_capacity = 2 * (end - start)];  
    memcpy(_elem, A + start, (end - start) * sizeof(T));
};

template<typename T>
MyVector<T>::MyVector(int c) {
    _elem = new T[_capacity = c];
    _size = 0;
}
// template<typename T>
// MyVector<T>::MyVector(int c, Size s, T v) {
//     if (c < s) {
//         printf("capacity must not be less than size!");
//         c = DEFAULT_CAPACITY;
//         s = 0;
//         v = 0;
//     }
//     _elem = new T[_capacity = c];
//     // code style check failed
//     // for (_size = 0; _size < s; _elem[_size++] = v); 
//     for (_size = 0; _size < s; _size++) {
//         _elem[_size] = v;
//     }
// };

template<typename T>
MyVector<T>::MyVector(T const* A, Size s) {
    _elem = new T[_capacity = 2 * s];
    copyFrom(A, 0, s);
}

template<typename T>
MyVector<T>::MyVector(T const* A, Rank start, Rank end) {
    copyFrom(A, start, end);
}

template<typename T>
T* MyVector<T>::data() {
    return _elem;
}

template<typename T>
MyVector<T>::MyVector(MyVector<T> const& V) {
    copyFrom(V.data(), 0, V.size());
}

template<typename T>
MyVector<T>::MyVector(MyVector<T> const& V, Rank start, Rank end) {
    copyFrom(V.data(), start, end);
};

template<typename T>
Size MyVector<T>::size() const {
    return _size;
}

template<typename T>
Rank MyVector<T>::find(T const e, Rank start, Rank end) {
    while (start < end)
    {
        if (e == _elem[start]) {
            return start;
        }
        start++;
    }
    return -1;
}

template<typename T>
Rank MyVector<T>::find(T const e) {
    return find(e, 0, size());
}

template<typename T>
Rank MyVector<T>::search(T const e, Rank start, Rank end) {
    if (e < _elem[start] || e > _elem[end] || start == end) {
        return -1;
    }
    Rank mid = (start + end) >> 1;
    if (_elem[mid] > e) {
        return search(e, start, mid);
    } else {
        return search(e, mid, end);
    }
}

template<typename T>
Rank MyVector<T>::search(T const e) {
    return search(e, 0, size());
}

template<typename T>
void MyVector<T>::expand() {
    T * newElem = new T[_capacity = _capacity * 2];
    for (int i = 0; i < _size; i++)
    {
        newElem[i] = _elem[i];
    }
    delete[] _elem;
    _elem = newElem;
}

template<typename T>
void MyVector<T>::shrink() {
    T* newElem = new T[_capacity = _size * 2];
    for (int i = 0; i < _size; i++)
    {
        newElem[i] = _elem[i];
    }
    delete[] _elem;
    _elem = newElem;
}

template<typename T>
bool MyVector<T>::isTooLong() {
    if (_capacity > _size * 2) {
        shrink();
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool MyVector<T>::isTooShort() {
    if (_capacity <= _size * 2) {
        expand();
        return true;
    } else {
        return false;
    }
}

template<typename T>
const T& MyVector<T>::operator[] (Rank r) const {
    return _elem[r];
}


template<typename T>
MyVector<T>& MyVector<T>::operator= (MyVector<T> const& V) {
    MyVector(v);
    return *this;
}

template<typename T>
int MyVector<T>::remove(Rank start, Rank end) {
    if (start >= end) {
        return 0;
    }
    while(end < _size) {
        _elem[start++] = _elem[end++];
    }
    _size = start;
    isTooLong();
    return end - start;
}

template<typename T>
Rank MyVector<T>::remove(Rank r) {
    return remove(r, r + 1);
}

template<typename T>
Rank MyVector<T>::insert(T const& e, Rank r) {
    while (r < _size)
    {
        _elem[r + 1] = _elem[r];
    }
    _elem[r] = e;
    isTooShort();
    return ++_size;
}

template<typename T>
Rank MyVector<T>::insert(T const& e) {
    insert(e, _size);
    return ++_size;

}

template<typename T>
int MyVector<T>::deduplicate() {
    for (int i = 0; i < _size; i++)
        for(int j = 0; j < _size;j++ )
        {
            if (_elem[i] == _elem[j] && i != j)
                remove(i);
                _size--;
        }
    return _size;
}

template<typename T>
int MyVector<T>::uniquify() {
    int start = 0;
    for (Rank r = 0; r < _size; r++)
    {
        if (_elem[r] != _elem[r + 1])
        {
            remove(start, r + 1);
            start = r + 1;
        }
    }
    return _size;
}

// template<typename T>
// const ostream& operator<< (const std::ostream& os, const MyVector<T>& vec) {
//    for (Rank r = 0; r < vec.size(); r++) {
//         os << vec[r] << " ";
//    }
//    return os;
// };