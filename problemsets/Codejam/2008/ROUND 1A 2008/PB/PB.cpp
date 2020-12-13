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

#define FOR(i,a,b) for (int i = a; i < b; i++)

using namespace std;

#define MAXF 2000

int can[MAXF][MAXF], ncan[MAXF];
int choice[MAXF];
int malted[MAXF];
int vis[MAXF];
        
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
        int N, M; scanf("%d %d", &N, &M);
        
        FOR(i,0,M) {
            malted[i] = -1;
            vis[i] = 0;
            ncan[i] = 0;
            FOR(j,0,N) can[i][j] = 0;
        }
        FOR(i,0,N) choice[i] = 0;

        FOR(i,0,M) {
            int t; scanf("%d", &t); 
            FOR(j,0,t) {
                int f, m; scanf("%d %d", &f, &m); f--;
                if (m) malted[i] = f;
                else { can[i][f] = 1; ncan[i]++; }
            }
        }
        
        bool possible = true;
        while (1) {
            bool found = false;
            FOR(i,0,M) if (!vis[i] && ncan[i]==0) {
                if (malted[i]==-1) { possible = false; break; }
                vis[i] = 1; found = true;
                choice[malted[i]] = 1;
                FOR(j,0,M) if (can[j][malted[i]]) {
                    can[j][malted[i]] = 0; ncan[j]--;
                }
            }
            if (!found || !possible) break;
        }

        printf("Case #%d:", tc);
        if (!possible) printf(" IMPOSSIBLE\n");
        else {
            FOR(i,0,N) (choice[i]) ? printf(" 1") : printf(" 0");
            putchar('\n');
        }
    }

	return 0;
}
