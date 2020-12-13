/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>

using namespace std;

unsigned DP[1000000];

unsigned go(unsigned N) {
    if (N<=1) return 1;
    if (N < 1000000 && DP[N]) return DP[N];
    if (N%2==0) {
        unsigned x = go(N/2)+1;
        if (N < 1000000) DP[N] = x;
        return x;
    }
    unsigned x = go(3*N+1)+1;
    if (N < 1000000) DP[N] = x;
    return x;
}

int main() {

    unsigned L, H, V, S;
    while (scanf("%u %u", &L, &H)) {
        if (!(L|H)) break;
        if (L > H) swap(L,H);
        unsigned x;
        S = 0; V = L;
        for (unsigned i = L; i <= H; i++) if ((x = go(i%2?i*3+1:i/2)) > S) {
            S = x;
            V = i;
        }
        printf("Between %u and %u, %u generates the longest sequence of %u values.\n", L, H, V, S);
    }

    return 0;
}
