/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

long long T[101010], V[101010];


int main() {

    int L = 1;
    T[L] = V[L] = 1;
    while (T[L] <= 2147483647) {
        L++;
        int c = 0, n = L;
        while (n) c++, n/=10;
        V[L] = V[L-1] + c;
        T[L] = T[L-1] + V[L];
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        long long X;
        scanf("%lld", &X);
        int p = (int)(lower_bound(T, T+L, X) - T);
        X -= T[p-1];
        int p2 = (int)(lower_bound(V, V+L, X) - V);
        X -= V[p2-1];
        char S[101];
        sprintf(S, "%d", p2);
        printf("%c\n", S[(int)X-1]);
    }

    return 0;
}
