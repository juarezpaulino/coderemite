/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <vector>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define BE(a) ((a).begin()),((a).end())
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a)) 
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()



#define MAXV 1000
#define INF 0x3F3F3F3F

using namespace std;

struct node {
    int first, second;
    node(int x = 0, int y = 0) : first(x), second(y) {}
};

char disc[MAXV][MAXV];
int t1, t2, l1, l2;
map<string, int> desc;
int adj1[MAXV][MAXV], type1[MAXV][MAXV], nadj1[MAXV];
vector<int> adj2[MAXV][MAXV];
int dist[MAXV][MAXV];
queue<node> q;

void BFS() {
    int i, x, x1, y, y1;
    q.push(node(0,0)); disc[0][0] = 1; dist[0][0] = 0;
    while (!q.empty()) {
        x = q.front().first; y = q.front().second; q.pop();
        if (x==t1 && y==t2) goto OUT;
        FOR(i, nadj1[x]) FORIT(it, all((adj2[y][type1[x][i]]))) {
            x1 = adj1[x][i]; y1 = *it;
            if (disc[x1][y1]) continue;
            dist[x1][y1] = dist[x][y]+1; disc[x1][y1] = 1;
            q.push(node(x1,y1));
        }
    }
OUT: while (!q.empty()) q.pop();
}


int main() {
    int t, i, j, x, y, k, p, v, f = 0;
    char str[10];
    for (scanf("%d", &t); t--; ) {
        (f)?putchar('\n'):(f=1);
        desc.clear(), k = 0;
        scanf("%d %d %d", &l1, &t1, &p);
        FOR(i, l1) nadj1[i] = 0;
        FOR(i, p) {
            scanf("%d %s %d", &x, str, &y); adj1[x][nadj1[x]] = y;
            if (desc.count(str)) type1[x][nadj1[x]] = desc[str];
            else type1[x][nadj1[x]] = desc[str] = k, k++;
            nadj1[x]++;
        }
        scanf("%d %d %d", &l2, &t2, &p);
        FOR(i, l2) FOR(j, k) adj2[i][j].clear();
        FOR(i, p) {
            scanf("%d %s %d", &x, str, &y);
            if (desc.count(str)) v = desc[str];
            else v = desc[str] = k, k++;
            adj2[x][v].push_back(y);
        }
        CLR(dist, INF); CLR(disc, 0); BFS();
        if (dist[t1][t2]!=INF) printf("%d\n", dist[t1][t2]);
        else printf("-1\n");
    }
    return 0;
}
