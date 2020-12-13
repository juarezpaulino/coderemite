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

#define FOR(i,m,n) for((i)=(m);(i)<(n);(i)++)
#define FORN(i,m,n) for((i)=(n)-1;(i)>=(m);(i)--)
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

const double PI = acos(-1.);

struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
};

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}

typedef pair<double, int> PDI;
int max_circle(vector<point> &T, int r) {
    int ret = 1, i, j, n = SI(T);
    vector<PDI> E;
    FOR(i,0,n) {
        E.clear();
        FOR(j,0,n) if(i != j) {
            int dx = T[j].x-T[i].x, dy = T[j].y-T[i].y;
            if(dx*dx + dy*dy > 2*r*2*r) continue;
            double d = sqrt((double)dx*dx + (double)dy*dy);
            double alfa = atan2((double)dy, (double)dx);
            double beta = acos(d/(2*r));
            E.PB(PDI(alfa - beta, 0));
            E.PB(PDI( alfa + beta, 1));
            E.PB(PDI( alfa - beta + 2*PI, 0));
            E.PB(PDI( alfa + beta + 2*PI, 1));
        }
        sort( E.begin(), E.end() );
        int curr = 1;
        FORIT(it, ALL(E)) (it->second==0) ? (curr++,ret>?=curr) : curr--;
   }
   return ret;
}

int main() {
    
    int n, r, i;
    for (;n = get_int(), r = get_int(), n+r;) {
        vector<point> T(n);
        FOR(i,0,n) T[i].x = get_int(), T[i].y = get_int();
        printf("It is possible to cover %d points.\n", max_circle(T,r));
    }
    
    return 0;
}
