/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int N, L, C;
int T[1010];
pair<int,int> DP[1010][510];
char vis[1010][510];

const int INF = 1<<30;

inline int SQR(int x) { return x*x; }

pair<int,int> go(int k, int t) {
    pair<int,int> &ret = DP[k][t];
    if (vis[k][t]) return ret;
    vis[k][t] = 1;
    if (k == N) return ret = make_pair(1,((t==0) ? 0 : (t >= 1 && t <=10) ? -C : SQR(t-10)));
    if (t == 0) {
        pair<int,int> u = go(k, L);
        return ret = make_pair(1+u.first, u.second);
    }
    ret = make_pair(INF,INF);
    if (t-T[k] >= 0) {
        pair<int,int> u = go(k+1, t-T[k]);
        ret = min(ret, u);
    }
    if (t < L) {
        pair<int,int> u = go(k, L);
        ret = min(ret, make_pair(1+u.first, u.second+((t==0) ? 0 : (t >= 1 && t <=10) ? -C : SQR(t-10))));
    }
    return ret;
}

int main() {

    int id = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        scanf("%d %d", &L, &C);
        for (int i = 0; i < N; i++) scanf("%d", T+i);
        for (int i = 0; i <= N; i++) for (int j = 0; j <= L; j++) vis[i][j] = 0;
        pair<int,int> ret = go(0,L);
        if (id > 1) putchar('\n');
        printf("Case %d:\n", id++);
        printf("Minimum number of lectures: %d\n", ret.first);
        printf("Total dissatisfaction index: %d\n", ret.second);
    }

    return 0;
}
