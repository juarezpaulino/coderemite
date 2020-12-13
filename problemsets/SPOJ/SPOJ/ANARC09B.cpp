/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef long long i64;

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main() {

    i64 X, Y;
    while (1) {
        scanf("%lld %lld", &X, &Y);
        if (!X && !Y) break;
        i64 C = gcd(X,Y);
        printf("%lld\n", (X/C) * (Y/C));
    }

    return 0;
}
