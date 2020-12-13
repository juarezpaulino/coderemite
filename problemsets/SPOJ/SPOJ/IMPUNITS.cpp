/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long i64;

int N;
i64 A[110], B[110];

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }


int main() {

    while (1) {
        scanf("%d", &N);
        if (N == -1) break;

        for (int i = 0; i < N-1; i++) {
            scanf("%lld %lld", A+i, B+i);
            i64 d = __gcd(A[i], B[i]);
            A[i] /= d; B[i] /= d;
        }

        i64 C = A[0], D = B[0], m;
        for (int i = 1; i < N-1; i++) {
            m = lcm(D,A[i]);
            C *= m/D;
            D = m/A[i] * B[i];
            m = __gcd(C, D);
            C /= m; D /= m;
        }

        printf("%lld %lld\n", C, D);
    }

    return 0;
}
