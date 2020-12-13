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
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
	freopen("B-large.in","r",stdin);freopen("B-large.ans","w",stdout);

    int TC;
    scanf("%d ", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        int C, D, N;
        char IN[1000];
        map<PCC, char> COMBINE;
        vector<char> REFUSE[300];
        int COUNT[300] = {0};

        // Read input.
        scanf("%d", &C);
        for (int i = 0; i < C; i++) {
            char S[10];
            scanf("%s", S);
            COMBINE[PCC(S[0],S[1])] = S[2];
            COMBINE[PCC(S[1],S[0])] = S[2];
        }
        scanf("%d", &D);
        for (int i = 0; i < D; i++) {
            char S[10];
            scanf("%s", S);
            REFUSE[S[0]].push_back(S[1]);
            REFUSE[S[1]].push_back(S[0]);
        }
        scanf("%d", &N);
        scanf("%s", IN);

        // Process input.
        vector<char> stack;
        for (int i = 0; i < N; i++) {
            // Try to combine.
            if (!stack.empty()) {
                char c = stack.back();
                PCC p = PCC(c,IN[i]);
                if (COMBINE.count(p)) {
                    stack.pop_back();
                    COUNT[c]--;
                    stack.push_back(COMBINE[p]);
                    COUNT[COMBINE[p]]++;
                    goto OUT;
                }
            }

            // Try to clean.
            for (int j = 0; j < REFUSE[IN[i]].size(); j++) {
                if (COUNT[REFUSE[IN[i]][j]] >= 1) {
                    memset(COUNT, 0, sizeof(COUNT));
                    stack.clear();
                    goto OUT;
                }
            }

            // Just append it.
            stack.push_back(IN[i]);
            COUNT[IN[i]]++;
OUT:;
        }

        // Build result.
        string ret = "[";
        for (int i = 0; i < stack.size(); i++) {
            ret += stack[i];
            if (i < stack.size() - 1) ret += ", ";
        }
        ret += "]";

        // Prints result.
        printf("Case #%d: %s\n", tc, ret.c_str());
    }

	return 0;
}
