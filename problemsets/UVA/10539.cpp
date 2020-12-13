/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

const double EPS = 1E-10;

vector<long long> AP;
vector<long long> pr;

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
    for (int i = 0; i < pr.size(); i++)
        for (long long k = pr[i]*pr[i]; k <= 1000000000000LL; k*=pr[i]) AP.push_back(k);
    sort(AP.begin(), AP.end());
    AP.resize(unique(AP.begin(), AP.end())-AP.begin());
}


int main() {

    sieve();
    int T;
    scanf("%d", &T);
    while (T--) {
        long long L, H;
        scanf("%lld %lld", &L, &H);
        int ret = lower_bound(AP.begin(), AP.end(), H) -
                  lower_bound(AP.begin(), AP.end(), L);
        printf("%d\n", ret);
    }

    return 0;
}
