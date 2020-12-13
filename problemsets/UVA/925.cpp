/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

char G[120][120];

int main() {

    int T;
    char S[10101], A[10101];
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) G[i][j] = G[j][i] = 0;
        map<string,int> mapa;
        vector<string> rmapa(N);
        for (int i = 0; i < N; i++) {
            scanf("%s", S);
            rmapa[i] = S;
        }
        sort(rmapa.begin(), rmapa.end());
        for (int i = 0; i < N; i++) mapa[rmapa[i]] = i;
        int M;
        scanf("%d", &M);
        while (M--) {
            scanf("%s", S);
            int u = mapa[S];
            int m;
            scanf("%d", &m);
            while (m--) {
                scanf("%s", A);
                int v = mapa[A];
                G[u][v] = 1;
            }
        }

        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
            G[i][j] |= G[i][k]&G[k][j];

        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
            if (G[i][k]&&G[k][j]) G[i][j] = 0;

        for (int k = 0; k < N; k++) {
            vector<int> ret;
            for (int i = 0; i < N; i++) if (G[k][i]) ret.push_back(i);
            if (ret.size() == 0) continue;
            printf("%s %d", rmapa[k].c_str(), ret.size());
            for (int i = 0; i < ret.size(); i++) printf(" %s", rmapa[ret[i]].c_str());
            putchar('\n');
        }
    }

    return 0;
}
