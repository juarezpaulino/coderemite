/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef vector<int> VI;

VI ADJ[100000];
int DEG[100000];
bool V[100000], DISC[100000];
int N;

int main() {

    queue<int> q;

    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        ADJ[u].push_back(v);
        ADJ[v].push_back(u);
        DEG[u]++; DEG[v]++;
    }

    for (int i = 0; i < N; i++) if (DEG[i]==1) q.push(i);

    int ret = 0;
    while (!q.empty()) {
        int i = q.front(); q.pop();
        DISC[i] = 1;
        bool c = 0;
        for (int j = 0; j < ADJ[i].size(); j++) if (DISC[ADJ[i][j]] && !V[ADJ[i][j]]) c = 1;
        if (c) { ret++; V[i] = 1; }
        for (int j = 0; j < ADJ[i].size(); j++) if (!DISC[ADJ[i][j]]) {
            DEG[ADJ[i][j]]--;
            if (DEG[ADJ[i][j]]==1) q.push(ADJ[i][j]);
        }
    }

    printf("%d\n", ret);

    return 0;
}
