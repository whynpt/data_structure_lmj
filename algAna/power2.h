#pragma once
// warning of double to int in math.pow()

inline int sqr(int num) { return num * num; }
int power2(int n)
{
    if (n == 0) {
        return 1;
    }
    if (1 == (n % 2)) {
        return 2 * sqr(power2(n / 2));
    } else {
        return sqr(power2(n / 2));
    }
}