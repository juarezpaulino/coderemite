/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a)) 
#define TLE while(1);
#define RTE printf("%d", 1/0);

using namespace std;
typedef vector<int> VI; typedef vector<double> VD; typedef vector<string> VS;
typedef vector<vector<int> > VVI; typedef vector<vector<string> > VVS;
typedef set<int> SI; typedef set<double> SD; typedef set<string> SS;
typedef pair<int,int> PII;
typedef signed long long i64; typedef unsigned long long u64;

#define EPS 1E-14
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}

#define MAXV 1000

struct point { int x, y; };

struct lista { point p; int pos; };

int n;
char poly[MAXV][2];         /* Pos 0 - vertical; Pos 1 - Horizontal. */
int dir[MAXV][2];           /* Posicao vizinha no poligono. */
lista H[MAXV], V[MAXV];


int xcmp(const void *x, const void *y) {
    lista *a = (lista *)x, *b = (lista *)y;
   if (a->p.x != b->p.x) return (a->p.x - b->p.x);
   return (a->p.y - b->p.y);
}

int ycmp(const void *x, const void *y) {
    lista *a = (lista *)x, *b = (lista *)y;
   if (a->p.y != b->p.y) return (a->p.y - b->p.y);
   return (a->p.x - b->p.x);
}



int main() {

   int i;
   int x, y, v;
   char found, tap;

   for(; n = get_int(), n;) {
       for (i = 0; i < n; i++) {
           x = get_int(), y = get_int();
           V[i].pos = H[i].pos = i;
           V[i].p.x = H[i].p.x = x;
           V[i].p.y = H[i].p.y = y;
       }

       qsort(V, n, sizeof(lista), ycmp);
       qsort(H, n, sizeof(lista), xcmp);

       for (i = 0; i < n; i += 2) {
           poly[H[i].pos][0] = 'N';    dir[H[i].pos][0] = H[i+1].pos;
           poly[H[i+1].pos][0] = 'S';  dir[H[i+1].pos][0] = H[i].pos;
           poly[V[i].pos][1] = 'E';    dir[V[i].pos][1] = V[i+1].pos;
           poly[V[i+1].pos][1] = 'W';  dir[V[i+1].pos][1] = V[i].pos;
       }

       found = 0;
       v = V[0].pos;
       tap = 0;
       while ((!found) || (v != 0)) {
           if (v == 0) found = 1;
           if (found) putchar(poly[v][tap]);
           v = dir[v][tap];
           tap ^= 1;
       }
       putchar('\n');
   }

   return 0;
}
