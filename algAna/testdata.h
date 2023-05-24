#pragma once
#include <stdlib.h> 
#include <array>
class testdata
{
private:
    int mLen;
    std::array<int, 1000> mArr = {0};
    
public:
    testdata(int len);
    int getlen();
    int* getarray();
    void setarray();
};

