/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <numeric>

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


////////////////////////////////////////////////////////////////////////////////

vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}


int main() {

//	freopen("D.in","r",stdin);
//	freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
//	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
//	freopen("D-small-attempt2.in","r",stdin);freopen("D-small-attempt2.out","w",stdout);
//	freopen("D-large.in","r",stdin);freopen("D-large.ans","w",stdout);

    int TC;
    scanf("%d ", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        int N, M;
        vector<int> ADJ[100];
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) {
            int u, w;
            scanf("%d,%d", &u, &w);
            ADJ[u].push_back(w);
            ADJ[w].push_back(u);
        }

        queue<int> Q;
        set<int> D[100], C[100];
        int V[100] = {0};
        Q.push(1);
        D[1].insert(1);
        int l = -1;
        while (!Q.empty()) {
            int t = Q.size();
            while (t--) {
                int u = Q.front(); Q.pop();
                if (V[u]) continue;
                V[u] = 1;
                if (u == 0) goto OUT;
                for (int i = 0; i < ADJ[u].size(); i++) {
                    int v = ADJ[u][i];
                    if (!V[v]) {
                        int c = 0;
                        for (int j = 0; j < ADJ[v].size(); j++)
                            if (!C[u].count(ADJ[v][j]) && ADJ[v][j]!=0 && !D[u].count(ADJ[v][j]))
                                c++;
                        if (D[u].size() - (u==1?0:1) + c > D[v].size()) {
                            D[v] = D[u];
                            D[v].erase(v);
                            for (int j = 0; j < ADJ[v].size(); j++)
                                if (!C[u].count(ADJ[v][j]) && ADJ[v][j]!=0 && !D[u].count(ADJ[v][j]))
                                    D[v].insert(ADJ[v][j]);
                            C[v] = C[u];
                            C[v].insert(v);
                            Q.push(v);
                        }
                    }
                }
            }
            l++;
        }

OUT:
        // Prints result.
        printf("Case #%d: %d %d\n", tc, l, D[0].size());
    }

	return 0;
}
