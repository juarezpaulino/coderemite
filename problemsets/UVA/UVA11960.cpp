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
#include <numeric>

using namespace std;

const int MAX = 1000000;

vector<int> pr;

const int LMT = sqrt(MAX)+1;
int flag[MAX>>6];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
    int i, j, k;
    for(i = 3; i < LMT; i += 2) if(!ifc(i))
        for(j = i*i, k = i<<1; j < MAX; j += k) isc(j);
    k = 0; pr.push_back(2);
    for (int i = 3; i < MAX; i += 2) if (!ifc(i)) pr.push_back(i);
}

int T;
int RET[MAX+10], TOT[MAX+10];

int main() {

    sieve();

    for (int v = 1; v <= MAX; v++) {
        int m = v;
        TOT[v] = 1;
        for (int j = 0; pr[j]*pr[j] <= v; j++) {
            int d = 0;
            while (m%pr[j] == 0) { d++; m/=pr[j]; }
            TOT[v] *= d+1;
        }
        if (m != 1) TOT[v] *= 2;
    }

    int best = 1;
    for (int v = 1; v <= MAX; v++) {
        if (TOT[best] <= TOT[v]) best = v;
        RET[v] = best;
    }

    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        printf("%d\n", RET[N]);
    }

    return 0;
}
