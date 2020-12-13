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

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)V.size()
#define PB push_back

typedef long long i64;
typedef vector<int> VI;

const int INF = 0x3F3F3F3F;
const double EPS = 1E-14;


const int MAXV = 5000;

int L, D, N;
char P[20][256];
char W[MAXV][20];


int main() {
    
//	freopen("A.in","r",stdin);
//	freopen("A-small-practice.in","r",stdin);freopen("A-small-practice.out","w",stdout);
  freopen("A-large-practice.in","r",stdin);freopen("A-large-practice.out","w",stdout);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.ans","w",stdout);

    scanf("%d%d%d", &L, &D, &N);
    FOR(i,0,D) scanf("%s", W[i]);
    FOR(i,1,N+1) {
        
        // Gets pattern.
        char p[1000]; scanf("%s", p);
        int k = 0; bool in = false;
        CLR(P, 0);
        for (int j = 0; p[j]; j++) {
            if (p[j]=='(') in = true;
            else if (p[j]==')') { k++; in = false; continue; }
            else {
                P[k][p[j]] = 1;
                if (!in) k++;
            }
        }
        
        // Compute # of words on pattern.
        int ret = 0;
        FOR(j,0,D) {
            bool ok = true;
            FOR(k,0,L) if (!P[k][W[j][k]]) { ok = false; break; }
            if (ok) ret++;
        }
        
        printf("Case #%d: %d\n", i, ret);
    }

	return 0;
}
