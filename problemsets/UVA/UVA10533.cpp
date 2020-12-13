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

const int MAX = 1000000, LMT = sqrt(MAX)+1;
int flag[MAX>>6];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
    int i, j, k;
    for(i = 3; i < LMT; i += 2) if(!ifc(i))
        for(j = i*i, k = i<<1; j < MAX; j += k) isc(j);
}

int DP[1000010];

int main() {

    sieve();
    DP[0] = DP[1] = 0;
    DP[2] = 1;
    for (int i = 3; i <= 1000000; i++) {
        DP[i] = DP[i-1];
        if (i%2 && !ifc(i)) {
            int n = i, m = 0;
            while (n) { m += n%10; n/=10; }
            if (m==2 || (m > 2 && m%2 && !ifc(m))) DP[i]++;
        }
    }

    int N;
    scanf("%d", &N);
    while (N--) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", DP[B]-DP[A-1]);
    }

    return 0;
}
