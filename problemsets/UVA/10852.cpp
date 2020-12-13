/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> pr;

const int MAXP = 20000, LMT = sqrt(MAXP) + 1;
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
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int m = -1, b = -1;
        for (int i = 0; pr[i] <= N; i++) if (N%pr[i] > b) {
            b = N%pr[i];
            m = pr[i];
        }
        printf("%d\n", m);
    }

    return 0;
}
