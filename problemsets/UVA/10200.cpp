/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long i64;

int TRUE[10101];

#define POWBIT 0x80000000
int powlog(int n, int p, int m) {
    int k; i64 c, r;
    for (k=31; !(p&POWBIT); k--, p<<=1); r = n;
    while (p<<=1, k--) { c = (r*r)%m; r = p&POWBIT ? (c*n)%m : c; }
    return r;
}

#define ACC 10
int rabin_miller(int n) {
    int n1 = n-1, s = __builtin_ctz(n), d = n1>>s, k, r;
    i64 y;
    for(k = ACC; k--; ) {
        int a = 2+(rand()%(n-2)), x = powlog(a, d, n);
        if (x==1 || x==n1) continue;
        for (r = 1; r < s; r++) {
            y = x; y*=x; x = (int)(y%n);
            if (x==1) return 0;
            if (x==n1) break;
        }
        if (r < s) continue; return 0;
    }
    return 1;
}

void sieve() {
    for (int k = 0; k <= 10000; k++) {
        int N = k*k + k + 41;
        bool ok = rabin_miller(N);
        TRUE[k] = ((k > 0) ? TRUE[k-1] : 0) + ok;
    }
}

int main() {

    sieve();

    int a, b;
    while (scanf("%d %d", &a, &b)!=EOF) {
        int n = (a==0) ? TRUE[b] : TRUE[b]-TRUE[a-1], m = b-a+1;
        if (m == 0) printf("100.00\n");
        else printf("%.2lf\n", n * 100. / m + 1E-10);
    }

    return 0;
}
