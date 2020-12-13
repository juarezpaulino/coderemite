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
#define ALL(M) (M).begin(), (M).end()
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)(V.size())
#define PB push_back
#define MP make_pair

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;

const int INF = 0x3F3F3F3F;
const i64 LINF = 0x3F3F3F3F3F3F3F3FLL;
const double EPS = 1E-14;

template<class T> T SQR(T x) { return x*x; }

////////////////////////////////////////////////////////////////////////////////

int L, A;
VS S; VI P; set<string> F;

double solve(int b, int e) {
    b++; e--;
    double p = atof(S[b].c_str());
    if (b>=e) return p;
    if (F.count(S[b+1])) return  p * solve(b+2,P[b+2]);
    else return p * solve(P[e], e);
}

int main() {
    
//	freopen("A.in","r",stdin);
//	freopen("A-small-practice.in","r",stdin);freopen("A-small-practice.out","w",stdout);
  freopen("A-large-practice.in","r",stdin);freopen("A-large-practice.out","w",stdout);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.ans","w",stdout);

    char str[100];
    int n;

    int TC;
    scanf("%d ", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        scanf("%d ", &L); S.clear();
        FOR(i,0,L) {
            gets(str);
            string s;
            for (int j = 0; str[j]; j++)
                if (str[j]=='(' || str[j]==')') s += " " + string(1,str[j]) + " ";
                else s += str[j];
            istringstream sin(s);
            while (sin >> s) S.PB(s);
        }
        
        // Fill in Position index reference for ().
        P.resize(SI(S), -1);
        VI ST;
        FOR(i,0,SI(S)) {
            if (S[i]=="(") ST.PB(i);
            else if (S[i]==")") {
                int p = ST[SI(ST)-1];
                ST.pop_back();
                P[p] = i; P[i] = p;
            }
        }
                
        // Prints result.
        printf("Case #%d:\n", tc);
        for (scanf("%d", &A); A--; ) {
            scanf("%*s");
            scanf("%d", &n); F.clear();
            while (n--) scanf("%s", str), F.insert(str);
            double ret = solve(0, SI(S)-1);
            printf("%.8lf\n", ret);
        }
    }

	return 0;
}
