/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <iostream>
#include <map>
#include <set>

using namespace std;

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(M) (M).begin(), (M).end()
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)(V.size())
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SORT(M) sort(ALL(M))
template<class T> inline void SORTG(vector<T> &M) { sort(ALL(M), greater<T>()); }
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = 0x3F3F3F3F;
const i64 LINF = 0x3F3F3F3F3F3F3F3FLL;
const double DINF = 1E16;
const double EPS = 1E-10;
const double PI = 3.1415926535897932384626433832795;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template<class T> T SQR(T x) { return x*x; }

template <class T> T gcd(T a, T b) { return (b!=0) ? gcd(b, a % b) : a; }

inline string ITOA(int a) { char c[500]; sprintf(c,"%d",(a)); return string(c); }

typedef pair<string, int> PSI;

bool is_solution(string U) {
    int i = 0, N = SI(U);
    while (i < N && U[i] != 'B') i++;
    while (i < N && U[i] != 'W') i++;
    while (i < N) {
        if (U[i]=='B') return false;
        i++;
    }
    return true;
}

int BFS(string S) {
    queue<PSI> Q;
    set<string> H;
    Q.push(MP(S,0)); H.insert(S);
    while (!Q.empty()) {
        string U = Q.front().first; int d = Q.front().second; Q.pop();
        if (is_solution(U)) return d;
        if (d == 9) continue;
        int p = U.find('F');
        string V;
        if (p > 0) {
            V = U; swap(V[p],V[p-1]);
            if (!H.count(V)) { H.insert(V); Q.push(MP(V,d+1)); }
        }
        if (p < SI(U)-1) {
            V = U; swap(V[p],V[p+1]);
            if (!H.count(V)) { H.insert(V); Q.push(MP(V,d+1)); }
        }
        if (p > 1) {
            V = U; swap(V[p],V[p-2]); V[p] = (V[p]=='W') ? 'B' : 'W';
            if (!H.count(V)) { H.insert(V); Q.push(MP(V,d+1)); }
        }
        if (p < SI(U)-2) {
            V = U; swap(V[p],V[p+2]); V[p] = (V[p]=='W') ? 'B' : 'W';
            if (!H.count(V)) { H.insert(V); Q.push(MP(V,d+1)); }
        }
    }
    return -1;
}


int main() {

    char S[110];

    int id = 1;
    while (scanf("%s", S) && *S!='-') {
        int ret = BFS(S);
        printf("%d. %d\n", id, ret);
        id++;
    }

    return 0;
}
