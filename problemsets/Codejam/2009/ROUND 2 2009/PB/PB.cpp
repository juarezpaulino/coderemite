/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>


using namespace std;

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(M) (M).begin(), (M).end()
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)(V.size())
#define PB push_back
#define MP make_pair
#define SORT(M) sort(ALL(M))
template<class T> inline void SORTG(vector<T> &M) { sort(ALL(M), greater<T>()); }
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = 0x3F3F3F3F;
const i64 LINF = 0x3F3F3F3F3F3F3F3FLL;
const double DINF = 1E14;
const double EPS = 1E-14;
const double PI = 3.1415926535897932384626433832795;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template<class T> T SQR(T x) { return x*x; }

template <class T> T gcd(T a, T b) { return (b!=0) ? gcd(b, a % b) : a; }

/*******************************************************************************
 * HASH
 ******************************************************************************/
struct STATE {
    int X[20], Y[20], deg;
    bool operator==(const STATE& S) const {
        for (int i = 0; i < 20; i++)
            if (X[i]!=S.X[i] || Y[i]!=S.Y[i]) return false;
        return true;
    }
};
#ifdef VCC
#include<hash_map>
#include<hash_set>
using namespace stdext;
#else
#include<ext/hash_map>
#include<ext/hash_set>
using namespace __gnu_cxx;
namespace __gnu_cxx {
	template<> struct hash<string> {
		size_t operator()(const string& X) const {
			return hash<const char*>() (X.c_str());
		}
	};
	template<> struct hash<STATE> {
		size_t operator()(const STATE& S) const {
            size_t p = 0;
            for (int i = 0; i < 20; i++) { p |= 1<<(S.Y[i]*6 + S.X[i]); }
            return p;
		}
	};
}
#endif

////////////////////////////////////////////////////////////////////////////////

const int MAXV = 60;

int R, C, F;
char CAVE[MAXV][MAXV];
int D[MAXV][MAXV][MAXV][MAXV];
char VIS[MAXV][MAXV][MAXV][MAXV];

struct Node {
    int y, x, s, t, d;
    bool operator<(const Node &B) const { return d > B.d; }
};

void add_node(priority_queue<Node> &Q, int y, int x, int s, int t, int d) {
    if (d >= D[y][x][s][t]) return;
    D[y][x][s][t] = d;
    Q.push((Node){y,x,s,t,d});
}

int main() {
    
//	freopen("B.in","r",stdin);
//	freopen("B-small-practice.in","r",stdin);freopen("B-small-practice.out","w",stdout);
	freopen("B-large-practice.in","r",stdin);freopen("B-large-practice.out","w",stdout);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        FOR(i,0,MAXV) FOR(j,0,MAXV) CAVE[i][j] = '#';
        scanf("%d%d%d", &R, &C, &F);
        FOR(i,1,R+1) { scanf("%s", CAVE[i]+1); CAVE[i][strlen(CAVE[i])] = '#'; }
                
        // Dijkstra bootstrap.
        FOR(i,0,R+1) FOR(j,0,C+1) FOR(k,0,R+1) FOR(l,0,C+1)
            D[i][j][k][l] = INF, VIS[i][j][k][l] = 0;
        priority_queue<Node> Q;
        D[1][1][1][0] = 0;
        Q.push((Node){1,1,1,0,0});
        
        int ret = -1;
        while (!Q.empty()) {
            int y = Q.top().y, x = Q.top().x, s = Q.top().s, t = Q.top().t;
            Q.pop();
            if (VIS[y][x][s][t]) continue;
            VIS[y][x][s][t] = 1;
            int d = D[y][x][s][t];
            if (y == R) { ret = d; break; }
            // Just walk around, possibly falling.
            for (int dx = -1; dx <= 1; dx+=2) {
                int x2 = x + dx;
                if (!(CAVE[y][x2]=='.' || x2 >= s && x2 <= t)) continue;
                int y2 = y;
                while (CAVE[y2+1][x2]=='.') y2++;
                if (y2-y > F) continue;
                if (y2==y) add_node(Q,y2,x2,s,t,d);
                else add_node(Q,y2,x2,1,0,d);
            }
            // Dig some available space and fall.
            for (int dx = -1; dx <= 1; dx+=2) {
                for (int x2 = x+dx; 1; x2+=dx) {
                    if (!(CAVE[y][x2]=='.' || x2 >= s && x2 <= t)) break;
                    if (CAVE[y+1][x2]=='.') break;
                    int x3 = x2-dx;
                    int y3 = y+1;
                    while (CAVE[y3+1][x3]=='.') y3++;
                    if (y3-y > F) continue;
                    if (y3 == y+1) add_node(Q,y3,x3,min(x3,x),max(x3,x),d+abs(x2-x));
                    else add_node(Q,y3,x3,1,0,d+abs(x2-x));
                }
            }
        }
        
        // Prints result.
        (ret == -1) ? printf("Case #%d: No\n", tc) :
                      printf("Case #%d: Yes %d\n", tc, ret);
    }

	return 0;
}
