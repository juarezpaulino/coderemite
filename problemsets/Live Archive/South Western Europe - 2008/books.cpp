/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define BE(a) ((a).begin()),((a).end())
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a)) 
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define TLE while(1);
#define RTE printf("%d", 1/0);

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T> T abs(T a)      { return a < 0 ? -a : a; }

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int main() {

    int i, x, c, maxan;
    long long N, s;
    for (int t = get_int(); t--; ) {
        c = get_int(); maxan = N = 0;
        while (c--) {
            s = 0; FOR(i,9) s+=get_int(); x = get_int(); maxan>?=x;
            s = abs(s-x); N = gcd(N, s);
        }
        if (N<=maxan) puts("impossible"); else printf("%lld\n", N);
    }
    
    return 0;
}
