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
#include <map>

using namespace std;

long long L, U;
vector<int> pr;
vector<int> PR;

const int MAXP = 46341, LMT = sqrt(MAXP) + 1;
int flag[MAXP>>6];
char FLAG[1010101];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
    int i, j, k;
    for(i = 3; i < LMT; i += 2) if(!ifc(i))
        for(j = i*i, k = i<<1; j < MAXP; j += k) isc(j);
    pr.push_back(2);
    for (int i = 3; i < MAXP; i += 2) if (!ifc(i)) pr.push_back(i);
}

void sieve2() {
    memset(FLAG,1,sizeof(FLAG));
    PR.clear();
    for (int l = 1, i; l < pr.size() && (i = pr[l], i*i <= U); l++) {
        long long b = (L <= i*i) ? i*i : (L+i-1) / i * i;
        if (b%2==0) b += i;
        for(long long j = b, k = 2*i; j <= U; j += k) FLAG[j-L] = 0;
    }
    if (L <= 1) FLAG[1-L] = 0;
    if (L <= 2) PR.push_back(2);
    for (int i = (L%2==0) ? 1 : 0; i <= U-L; i+=2) if (FLAG[i]) PR.push_back(L+i);
}

int main() {

    sieve();
    while (scanf("%lld %lld", &L, &U) != EOF) {
        sieve2();
        pair<int,int> C(-1,100000000), D(-1,-2);
        for (int i = 1; i < PR.size(); i++) {
            if (PR[i]-PR[i-1] < C.second-C.first) C = make_pair(PR[i-1], PR[i]);
            if (PR[i]-PR[i-1] > D.second-D.first) D = make_pair(PR[i-1], PR[i]);
        }
        if (C.first == -1) puts("There are no adjacent primes.");
        else printf("%d,%d are closest, %d,%d are most distant.\n", C.first, C.second, D.first, D.second);
    }

    return 0;
}
