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
typedef pair<char,char> PCC;

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


int main() {

//	freopen("B.in","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.ans","w",stdout);

    int TC;
    scanf("%d ", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        vector<string> D;
        vector<string> L;
        int N, M;

        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) {
            char S[10000];
            scanf("%s", S);
            D.push_back(S);
        }

        for (int i = 0; i < M; i++) {
            char S[10000];
            scanf("%s", S);
            L.push_back(S);
        }

        vector<string> RET(M);
        for (int i = 0; i < M; i++) {
            int b = -1;
            for (int j = 0; j < N; j++) {
                int K = D[j].size();
                vector<string> P;
                for (int k = 0; k < N; k++) if (D[k].size() == K)
                    P.push_back(D[k]);
                int p = 0;
                int count = 0;
//                printf("Word: %s\n", D[j].c_str());
                while (P.size() > 1 && p < 26) {
  //                  for (int i = 0; i < P.size(); i++) printf("%s\n", P[i].c_str());
                    char c = L[i][p];
                    bool ok = false;
                    for (int k = 0; k < P.size(); k++) if (P[k].find(string(1,c)) != -1)
                        ok = 1;

                    if (!ok) { p++; continue; }

                    if (D[j].find(string(1,c))==-1) {
                        count++; p++;
                        vector<string> P2;
                        for (int k = 0; k < P.size(); k++) if (P[k].find(string(1,c)) == -1)
                            P2.push_back(P[k]);
                        P = P2;
                        continue;
                    }

                    vector<string> P2;
                    for (int k = 0; k < P.size(); k++) {
                        bool ok = true;
                        for (int m = 0; m < K; m++) {
                            if (P[k][m]==c && D[j][m]!=c) ok = false;
                            if (P[k][m]!=c && D[j][m]==c) ok = false;
                        }
                        if (ok) P2.push_back(P[k]);
                    }
                    P = P2;

                    p++;
                }
                if (count > b) { b = count; RET[i] = D[j]; }
            }
        }

        // Prints result.
        printf("Case #%d:", tc);
        for (int i = 0; i < RET.size(); i++) printf(" %s", RET[i].c_str());
        putchar('\n');
    }

	return 0;
}
