#include"fib.h"

namespace fib {
    FibArray::FibArray(int n) {
        f = 1;
        g = 0;
        while (g < n) {
            next();
        }
    }

    int FibArray::get() {
        return g;
    }

    int FibArray::next() {
        g += f;
        f = g - f;
        return g;
    }

    int FibArray::prev() {
        f = g - f;
        g = g - f;
        return g;
    }
}
