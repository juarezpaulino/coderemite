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

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define SI(V) (int)V.size()
#define PB push_back

typedef long long i64;
typedef vector<int> VI;

const int MAXV = 1000010;

////////////////////////////////////////////////////////////////////////////////
// Union-Find Disjoint Set
// Set Rank counting on abs(up[r]), where up[r] < 0.
// 
int up[MAXV];
inline void init(int N) { FOR(i,0,N) up[i] = -1; }
inline int root(int k) { return up[k] < 0 ? k : up[k] = root(up[k]); }
bool join(int A, int B) {
    A = root(A); B = root(B);
    if (A == B) return false;
    if (up[A] > up[B]) swap(A, B);
    up[A] += up[B]; up[B] = A;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
        
int PR[MAXV];
VI pr;
i64 A, B, P;
i64 N;

int main() {
    
//	freopen("B.in","r",stdin);
//	freopen("B-small-practice.in","r",stdin);freopen("B-small-practice.out","w",stdout);
	freopen("B-large-practice.in","r",stdin);freopen("B-large-practice.out","w",stdout);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.ans","w",stdout);

    // Generate primes.
    fill(PR, PR+MAXV, 1);
    pr.PB(2); for (int i = 4; i < MAXV; i+=2) PR[i] = 0;
    for (i64 i = 3; i < MAXV; i+=2) if (PR[i]) {
        pr.PB(i);
        for (i64 j = i*i; j < MAXV; j += 2*i) PR[j] = 0;
    }

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%lld %lld %lld", &A, &B, &P);
        N = B-A+1;
        init(N);
        // Use sieve to compute sets.
        for (int i = 0; i < SI(pr) && pr[i] < N; i++) if (pr[i] >= P) {
            i64 j = ((A+pr[i]-1) / pr[i]) * pr[i];
            for (i64 k = j+pr[i]; k <= B; k += pr[i]) join(j-A, k-A);
        }
        int ret = 0; for (int i = 0; i < N; i++) if (up[i]<0) ret++;

        printf("Case #%d: %d\n", tc, ret);
    }

	return 0;
}
