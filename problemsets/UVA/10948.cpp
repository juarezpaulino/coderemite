/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> pr;

const int MAXP = 1000000, LMT = sqrt(MAXP) + 1;
int flag[MAXP>>6];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
    int i, j, k;
    for(i = 3; i < LMT; i += 2) if(!ifc(i))
        for(j = i*i, k = i<<1; j < MAXP; j += k) isc(j);
    pr.push_back(2);
    for (int i = 3; i < MAXP; i += 2) if (!ifc(i)) pr.push_back(i);
}


int main() {

    sieve();

    int N;
    while (1) {
        scanf("%d", &N);
        if (!N) break;
        if (N == 4) {
            printf("%d:\n%d+%d\n", 4, 2, 2);
        }
        else if (N&1) {
            if (!ifc(N-2)) printf("%d:\n%d+%d\n", N, 2, N-2);
            else printf("%d:\nNO WAY!\n", N);
        }
        else {
            bool ok = 0;
            for (int i = 1; !ok && pr[i] <= N/2; i++) {
                if (!ifc(N-pr[i])) { ok = 1, printf("%d:\n%d+%d\n", N, pr[i], N-pr[i]); }
            }
            if (!ok) printf("%d:\nNO WAY!\n", N);
        }
    }

    return 0;
}
