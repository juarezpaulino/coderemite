/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <algorithm>

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


struct num {
    int val[101]; int n;
    num() {}
};

int n, p;
num mem[10001];

void mult_num(num &a, num &b, num &r) {
    int i, j, k; int s, u;
    r.n = a.n+b.n-1;
    FOR(i, min(r.n, 101)) r.val[i] = 0;
    for (i = 0; (i < a.n) && (i <= 100); i++) for (j = 0; (j < b.n) && (i+j <= 100); j++) {
        s = *(a.val+i), u = *(b.val+j); s = (s*u)%1300031;
        k = (int)s;
        *(r.val+i+j) = (*(r.val+i+j)+k)%1300031;
    }
}

/*void pow_num(num &a, int p) {
    if (disc[p]) return;
    int i = p/2, j = (p/2)*2;
    pow_num(a, i);
    if (!disc[j]) { mult_num(mem[i], mem[i], mem[j]); disc[j] = 1; }
    if (p!=j) { mult_num(a, mem[j], mem[p]); disc[p] = 1; }
}*/

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


int main() {
    int i, j, k;
    mem[1].val[0] = mem[1].val[3] = 1; mem[1].val[1] = mem[1].val[2] = 3; mem[1].n = 4;
    mem[0].val[0] = 1; mem[0].n = 1;
    for (k = 2; k <= 10000; k++) {
        mem[k].n = mem[k-1].n+3; FOR (i, min(mem[k].n, 101)) mem[k].val[i] = 0;
        FOR(i, min(mem[k].n, 101)) {
            if (i<mem[k-1].n) mem[k].val[i] = (mem[k].val[i]+mem[k-1].val[i])%1300031;
            if (i>=1 && i-1<mem[k-1].n) mem[k].val[i] = (mem[k].val[i]+3*mem[k-1].val[i-1])%1300031;
            if (i>=2 && i-2<mem[k-1].n) mem[k].val[i] = (mem[k].val[i]+3*mem[k-1].val[i-2])%1300031;
            if (i>=3 && i-3<mem[k-1].n) mem[k].val[i] = (mem[k].val[i]+mem[k-1].val[i-3])%1300031;
        }
    }
    for (int t = get_int(); t--; ) {
        n = get_int(); p = get_int();
        if (p >= mem[n].n) printf("0\n");
        else printf("%d\n", mem[n].val[p]);
    }
    return 0;
}

