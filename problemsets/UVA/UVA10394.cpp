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

const int MAX = 18500000, LMT = sqrt(MAX)+1;
int flag[MAX>>6];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

int pr[100000];

void sieve() {
    int i, j, k;
    for(i = 3; i < LMT; i += 2) if(!ifc(i))
        for(j = i*i, k = i<<1; j < MAX; j += k) isc(j);
    k = 0;
    for (int i = 3; i < MAX && k < 100000; i+=2) if (!ifc(i) && !ifc(i+2)) pr[k++] = i;
}

int main() {

    int N;
    sieve();
    while (scanf("%d", &N) != EOF) {
        printf("(%d, %d)\n", pr[N-1], pr[N-1]+2);
    }

    return 0;
}
