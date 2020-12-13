/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

typedef long long ll;

ll go(ll n, ll k) {
    if (k == 1LL) return n;
    if (n%2==0 && k%2) return go((n-1)>>1, k>>1);
    return go(n>>1, k>>1);
}

int main() {

    int T;
    ll N, K;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%lld %lld", &N, &K);
        ll ret = go(N,K);
        printf("%lld %lld\n", ret>>1, (ret-1)>>1);
    }

    return 0;
}
