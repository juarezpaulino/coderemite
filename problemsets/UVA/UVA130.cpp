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
#include <set>
#include <queue>
#include <list>

using namespace std;


int V[110];
int N, K, I;

int josephus(int N, int K, int I) {
    if (N == 1) return 1;
    int p = I, p2;
    int M = N;
    for (int i = 0; i < N; i++) V[i] = i+1;
    do {
        p = (p+K-1)%M;
        p2 = (p+K-1)%(M-1);
        if (p2 >= p) p2 = (p2+1)%M;
        int v = V[p2];
        swap(V[p], V[p2]);
        copy(V+p2+1, V+M, V+p2);
        M--;
        for (int i = 0; i < M; i++) if (V[i]==v) { p = i; break; }
        p = (p+1)%M;
    } while (M > 1);
    return V[0];
}

int main() {

    while (scanf("%d %d", &N, &K) != EOF) {
        if (!(N|K)) break;
        for (I = 0; I < N; I++) if (josephus(N,K,I)==1) break;
        printf("%d\n", I+1);
    }

    return 0;
}
