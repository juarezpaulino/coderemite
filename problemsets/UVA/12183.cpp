/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a))
#define TLE while(1);
#define RTE printf("%d", 1/0);

#define POWBIT 0x80000000

using namespace std;

typedef long long ll;

int t, n, s, l, r, x, mod;
ll msg[1000], circ_mat[1000], dec_mat[1000];

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

void copy_circ_mat(ll *r, ll *a) { int i; FOR(i, n) r[i] = a[i]; }

void mult_circ_mat(ll *a, ll *b, ll *r) {
    int i, j;
    FOR(i, n) r[i] = 0;
    FOR(i, n) FOR(j, n) r[i] = (r[i]+a[j]*b[(i+n-j)%n]) % mod;
}

void pow_circ_mat(ll *a, int p, ll *r) {
    int i, j, k; ll c[1000];
    if (!p) { FOR(i, n) r[i] = 0; r[0] = 1; return; }
    for (k=31; !(p&POWBIT); k--, p<<=1); copy_circ_mat(r, a);
    while (p<<=1, k--) {
        mult_circ_mat(r, r, c); p&POWBIT ? mult_circ_mat(c, a, r) : copy_circ_mat(r, c);
    }
}


int main() {
    int i, j, k;
    ll sum;
    for (t = get_int(); t--; ) {
        n = get_int(), s = get_int(), l = get_int(), r = get_int(), x = get_int();
        FOR(i, n) msg[i] = get_int(), circ_mat[i] = 0;
        circ_mat[0] = 1; circ_mat[1] = r; circ_mat[n-1] = l;
        for (mod = 1; x--; mod*=10);
        pow_circ_mat(circ_mat, s, dec_mat);
        FOR(i, n) {
            sum = 0; FOR(j, n) sum = (sum + dec_mat[(j+n-i)%n]*msg[j]) % mod;
            k = sum; printf("%d%c", k, (i<n-1)?' ':'\n');
        }
    }
    return 0;
}
