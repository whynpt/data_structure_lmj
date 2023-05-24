#pragma once

namespace fib
{
    class FibArray
    {
    public:
        FibArray(int n);
        int get();
        int next();
        int prev();
    private:
        int f, g;
    };
}

