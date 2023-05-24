#include "testdata.h"
#include <cstdlib>

//constexpr auto array_length = 100;

testdata::testdata(int length)
{
    mLen = length;
    setarray();
};

int testdata::getlen()
{
    return mLen;
};

void testdata::setarray()
{
    for (int i = 0; i < mLen; i++)
        mArr[i] = rand() % mLen;
};

int* testdata::getarray()
{
    return &(mArr[0]);
}