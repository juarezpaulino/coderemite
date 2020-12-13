/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int INF = 0x3F3F3F3F;

struct Edge { int v, c, l; };

int K, N, R;
vector<Edge> adj[100]

int MINCOST[100][10100];


int go() {

}


int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &K, &N, &R);
        memset(nadj,0,sizeof(nadj));
        memset(COST,INF,sizeof(COST));
        for (int i = 0; i < R; i++) {
            int s, d, l, t;
            scanf("%d %d %d %d", &s, &d, &l, &t);
            s--; d--;
            adj[s].push_back((Edge){d,t,l});
        }

        int ret = go();
        printf("%d\n", ret);
    }

    return 0;
}
