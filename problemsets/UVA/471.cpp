/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

ll N;

void go() {
    ll u;
    queue<pair<int,int> > q;
    for (int i = 1; i < 10; i++) q.push(make_pair(i,1<<i));
    while (!q.empty()) {
        int v = q.front().first, n = q.front().second; q.pop();
        if ((u = v*N) >= 10000000000LL) break;
        ll k = u;
        int m = 0;
        bool ok = 1;
        while (k) { if (m & 1<<(k%10)) { ok = 0; break; } m |= 1<<(k%10); k /= 10; }
        if (ok) printf("%lld / %d = %lld\n", u, v, N);
        for (int i = 0; i < 10; i++) if (!(n & 1<<i))
            q.push(make_pair(v*10+i,n|1<<i));
    }
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &N);
        go();
        if (T) putchar('\n');
    }

    return 0;
}
