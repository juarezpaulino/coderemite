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
#define CLR(M,v) memset(M, v, sizeof M)
#define SI(V) (int)V.size()
#define PB push_back

typedef long long i64;
typedef vector<int> VI;

const int INF = 0x3F3F3F3F;
const double EPS = 1E-14;

const int MAXV = 100;

int M, N;
int H[MAXV][MAXV];
char L[MAXV][MAXV];
char cur;

char DFS(int y, int x) {
    static int dy[] = { -1, 0, 0, 1};
    static int dx[] = { 0, -1, 1, 0};
    
    if (L[y][x] != -1) return L[y][x];
    
    int by, bx, k = H[y][x];
    FOR(i,0,4) {
        int ny = y+dy[i], nx = x+dx[i];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if (H[ny][nx] < k) {
            k = H[ny][nx]; by = ny; bx = nx;
        }
    }
    
    if (k != H[y][x]) return L[y][x] = DFS(by, bx);
    return L[y][x] = cur++;
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
        scanf("%d%d", &M, &N);
        FOR(i,0,M) FOR(j,0,N) scanf("%d", &H[i][j]);
        
        // Compute labels.
        CLR(L,-1); cur = 'a';
        FOR(i,0,M) FOR(j,0,N) if (L[i][j]==-1) DFS(i,j);
        
        // Prints result.
        printf("Case #%d:\n", tc);
        FOR(i,0,M) FOR(j,0,N) printf((j==N-1) ? "%c\n" : "%c ", L[i][j]);
    }

	return 0;
}
