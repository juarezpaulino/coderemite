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

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;

const int INF = 0x3F3F3F3F;
const double EPS = 1E-14;

template<class T> T SQR(T x) { return x*x; }

const int MAXB = 11;
const int MAXV = 1000;

int H[MAXB][MAXV];

int OP(int N, int B) { int S = 0; while (N) { S += SQR(N%B); N/=B; } return S; }

int HAPPY(int N, int B) {
    if (N >= 1000) N = OP(N,B);
    if (N == 1) return 1;
    int &ret = H[B][N];
    if (ret != -1) return ret;
    ret = 0;
    return ret = HAPPY(OP(N,B), B);
}


char S[100];

int main() {
    
//	freopen("A.in","r",stdin);
//	freopen("A-small-practice.in","r",stdin);freopen("A-small-practice.out","w",stdout);
 freopen("A-large-practice.in","r",stdin);freopen("A-large-practice.out","w",stdout);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.ans","w",stdout);

    CLR(H,-1);
    
    int TC;
    scanf("%d ", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        gets(S);
        istringstream iss(S);
        VI B; int x;
        while (iss >> x) B.PB(x);
        
        int K = 2;
        while (1) {
            int i; for (i = 0; i < SI(B); i++) if (!HAPPY(K,B[i])) break;
            if (i == SI(B)) break;
            K++;
        }
        
        // Prints result.
        printf("Case #%d: %d\n", tc, K);
    }

	return 0;
}
