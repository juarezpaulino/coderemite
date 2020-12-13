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

int N, M;
int U[3000], V[3000];
vector<int> ADJ[3000];
set<int> DONT[3000], WALL;
int MARK[3000];
vector<vector<int> > COMP;
int VIS[3000], par[3000];
int COLOR[3000];

void add_comp(int r, int u) {
    vector<int> c;
    while (u != r) {
        c.push_back(u);
        u = par[u];
    }
    c.push_back(r);
    COMP.push_back(c);
}

void DFS(int v, int l) {
    if (VIS[v]) add_comp(v, par[v]);
    VIS[v] = 1;
    for (int i = 0; i < ADJ[v].size(); i++) {
        if (ADJ[v][i] != l) DFS(ADJ[v][i], v);
    }
}

bool comp(const vector<int> &A, const vector<int> &B) {
    return A.size() < B.size();
}

void reduce() {
    sort(COMP.begin(), COMP.end(), comp);
    vector<vector<int> > RET;
    set<int> OUT;
    for (int i = 0; i < COMP.size(); i++) if (!OUT.count(i)) {
        set<int> V;
        for (int j = 0; j < COMP[i].size(); j++) V.insert(COMP[i][j]);
        bool out = true;
        for (int j = i+1; j < COMP.size(); j++) if (!OUT.count(j)) {
            for (int k = 0; k < COMP[j].size(); k++) if (!V.count(COMP[j][k])) {
                out = false;
                break;
            }
            if (out) OUT.insert(j);
        }
    }
    for (int i = 0; i < COMP.size(); i++) if (!OUT.count(i))
        RET.push_back(COMP[i]);
    COMP = RET;
}

int main() {

//	freopen("C.in","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.ans","w",stdout);

    int TC;
    scanf("%d ", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) scanf("%d", U+i);
        for (int i = 0; i < M; i++) scanf("%d", V+i);

        for (int i = 1; i <= N; i++) ADJ[i].clear(), DONT[i].clear(), MARK[i] = 0;
        for (int i = 0; i < M; i++) {
            WALL.insert(U[i]);
            WALL.insert(V[i]);
            ADJ[U[i]].push_back(V[i]);
            ADJ[V[i]].push_back(U[i]);
            MARK[U[i]] = 1;
            MARK[V[i]] = 1;
        }
        for (int i = 1; i <= N; i++) {
            if (i == N) {
                ADJ[i].push_back(1);
                ADJ[1].push_back(i);
            }
            else {
                ADJ[i].push_back(i+1);
                ADJ[i+1].push_back(i);
            }
        }

        COMP.clear();
        par[1] = -1;
        for (int i = 1; i <= N; i++) VIS[i] = 0;
        DFS(1, -1);
        reduce();

        int COLOR[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        do {
            for (int i = 0; i < COMP.size(); i++)
        } while (next_permutation(COLOR, COLOR+N));

        // Prints result.
        printf("Case #%d: ", tc);
    }

	return 0;
}
