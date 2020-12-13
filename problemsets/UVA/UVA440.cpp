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

int V[100];

int josephus(int N, int K) {
    int p = -1;
    int M = N-1;
    for (int i = 0; i < N; i++) V[i] = i+2;
    do {
        p = (p+K)%M;
        copy(V+p+1, V+M, V+p);
        M--;
        p = (p+M-1)%M;
    } while (M > 1);
    return V[0];
}

int S[200];

int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        if (S[N]) { printf("%d\n", S[N]); continue; }
        int k;
        for (k = 2; ; k++) if (josephus(N,k)==2) break;
        printf("%d\n", S[N] = k);
    }

    return 0;
}
