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
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int N;
int adj[110][110];
int id = 1;

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        int u, v;
        while (1) {
            scanf("%d", &u);
            if (!u) break;
            while (scanf("%d", &v)) {
                if (!v) break;
                adj[u][v] = id;
            }
        }
        for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
            if (adj[i][k]==id && adj[k][j]==id) adj[i][j] = id;
        }
        int Q;
        scanf("%d", &Q);
        while (Q--) {
            vector<int> R;
            scanf("%d", &u);
            int ret = 0;
            for (int i = 1; i <= N; i++) if (adj[u][i]!=id) {
                ret++;
                R.push_back(i);
            }
            printf("%d", ret);
            for (int i = 0; i < R.size(); i++) printf(" %d", R[i]);
            putchar('\n');
        }
        id++;
    }

    return 0;
}
