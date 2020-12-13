/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/***********************************************************************************************************/
/*                                 Declarations, macros, parser functions                                  */
/***********************************************************************************************************/

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
#include <bitset>

using namespace std;

#define FOR(i,m,n) for((i)=(m);(i)<(n);(i)++)
#define FORE(i,m,n) for((i)=(m);(i)<=(n);(i)++)
#define ROF(i,m,n) for((i)=(m);(i)>=(n);(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a))
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())


inline string ITOA(int a) {
    char c[500]; sprintf(c, "%d", (a)); return string(c);
}

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PII;
typedef signed long long i64;
typedef unsigned long long u64;

#define EPS 1E-9
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1
#define PI 3.1415926535897932384626433832795

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int n;

struct card {
    int time;
    char t;
    card(int time = 0, int t = 0) : time(time), t(t) {}
    bool operator<(const card &b) const {
        if (time != b.time) return time < b.time;
        return t < b.t;
    }
};

int get_time(int h, int m, int s) { return (h*3600+m*60+s); }

int main() {

    int h, m, s;
    int i;
    char ch;
    int E, D;
    for(; scanf("%d", &n) && n; ) {
        vector<card> C(n);
        E = 0;
        FOR(i,0,n) {
            scanf("%d:%d:%d %c", &h, &m, &s, &ch);
            if (ch=='E') E++;
            C[i] = card(get_time(h, m, s), ch);
        }
        SORT(C);
        D = (n/2);
        for (i = 0; i < n ; i++) {
            if (C[i].t=='?') {
                if (E < D) { C[i].t = 'E'; E++; }
                else { C[i].t = 'X'; }
            }
        }
        int maxi = 1, count = 0;
        FOR(i,0,n) {
            if (C[i].t=='E') count++;
            else if (C[i].t=='X') count--;
            maxi = max(maxi,count);
        }
        printf("%d\n", maxi);
    }

    return 0;
}
