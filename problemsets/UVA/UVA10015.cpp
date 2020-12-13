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

using namespace std;

int pr[3600];

const int MAX = 32611, LMT = sqrt(MAX)+1;
int flag[MAX>>6];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
    int i, j, k;
    for(i = 3; i < LMT; i += 2) if(!ifc(i))
        for(j = i*i, k = i<<1; j < MAX; j += k) isc(j);
    k = 0; pr[k++] = 2;
    for (int i = 3; i < MAX; i += 2) if (!ifc(i)) pr[k++] = i;
}

int V[3600];

int josephus(int N) {
    if (N==1) return 1;
    int K = 0;
    int p = -1;
    int M = N;
    for (int i = 0; i < N; i++) V[i] = i+1;
    do {
        p = (p+pr[K++])%M;
        copy(V+p+1, V+M, V+p);
        M--;
        p = (p+M-1)%M;
    } while (M > 1);
    return V[0];
}

int N;

int main() {
    sieve();
    while (scanf("%d", &N)) {
        if (!N) break;
        printf("%d\n", josephus(N));
    }

    return 0;
}
