/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long i64;

int T;

int main() {

    scanf("%d ", &T);
    while (T--) {
        i64 ret = 0;
        i64 num;
        char op, op2 = -1;
        while (op2 != '=') {
            scanf("%lld %c", &num, &op);
            if (op2 == -1) ret = num;
            else if (op2 == '+') ret += num;
            else if (op2 == '-') ret -= num;
            else if (op2 == '*') ret *= num;
            else if (op2 == '/') ret /= num;
            op2 = op;
        }
        printf("%lld\n", ret);
    }

    return 0;
}
