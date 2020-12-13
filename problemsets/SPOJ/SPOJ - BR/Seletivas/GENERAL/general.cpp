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

using namespace std;

long long mergecount (vector<int> &a) {
    long long count = 0;
    int i, j, k, n = a.size();
    if (n <= 1) return 0; 
    vector<int> b(a.begin(), a.begin()+n/2);
    vector<int> c(a.begin()+n/2, a.end());
    count += mergecount(b); count += mergecount(c); 
    for  (i = j = k = 0 ; i < n; ++i)
        if  (k == c.size()) a[i] = b[j++];
        else if  (j == b.size()) a[i] = c[k++];
        else if  (b[j] <= c[k]) a[i] = b[j++];
        else a[i] = c[k++], count += n/2-j;
    return count;
}


int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int n, p;
long long trocas;
int val[100100];

int main() {
    int i, j;
    for (int t = get_int(); t--; ) {
        n = get_int(), p = get_int(); trocas = 0;
        FOR(i, n) val[i] = get_int();
        FOR(i, p) {
            vector<int> v;
            for (j = i; j < n; j+=p) v.PB(val[j]);
            trocas += mergecount(v);
            for (j = i; j < n; j+=p) val[j] = v[j/p];
        }
        FOR(i, n-1) if (val[i]>val[i+1]) break;
        if (i < n-1) printf("impossivel\n");
        else printf("%lld\n", trocas);
    }
    return 0;
}

