#include<iostream>
#include "MyVector.h"

using namespace std;

int dice(int range) { return rand() % range; }// get random number from [0, range)
int main()
{
    int size = 30;
    int a[5] = {1, 2, 3};
    MyVector<int> vec(3);
    // MyVector<int> vec(3, 0, 0);
    // for (int i = 0; i < size; i++) {
    //     vec.insert(dice(2 * size));
    // }
    ////vector V(20, 5, 1000);//  ���ֽڴ�����ֵĵ�λ
    // std::cout << vec;
    // V.sort(0, size);
    // V.print();
    // //V.remove(2, 5);
    // V.uniquify();
    // V.print();
    //vector<int> V1(V); 
    //vector<int> V2(V, 1, 3);
    //vector<int> V3(b, 5);  //�������帴��û����
    //vector<int> V4(a, 10);
    //vector<int> V5(b, 10);
    //V4.deduplicate();
    //V5.uniquify();
    //V4.print();
    //cout << endl;
    //V5.print();
    //cout<<V4;
    //cout<<V3.find(7, 1, 4);
    //V.TooLong();
    //cout << "size:"<<V.size()<<"  "<<V[2];
    //system("pause");
    return 0;

}

/* �ʼ�
    ���������ָ��Ƴ������⣺ CRT detected that the application wrote to memory after end of heap buffer
    ��copyFrom�������ٵ��������󣬽������

*/