/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int G[110][110];

int main() {

    int C;
    char A[1010], B[1010];
    int id = 1;
    while (scanf("%d", &C) && C) {
        int N = 0;
        map<string,int> mapa;
        vector<string> rmapa;
        for (int i = 0; i < 100; i++) for (int j = i+1; j < 100; j++) G[i][j] = G[j][i] = 0;
        int u, v;
        for (int i = 0; i < C; i++) {
            int c; scanf("%d", &c);
            for (int i = 0; i < c; i++) {
                scanf("%s", A);
                if (!mapa.count(A)) mapa[A] = N++, rmapa.push_back(A);
                u = v;
                v = mapa[A];
                if (i) G[u][v] = 1;
            }
        }
        int M;
        scanf("%d", &M);
        while (M--) {
            scanf("%s %s", A, B);
            u = mapa[A]; v = mapa[B];
            G[u][v] = 1;
        }

        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
            G[i][j] |= G[i][k]&G[k][j];

        int K = 0;
        vector<pair<int,int> > ret;
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++)
            if (!G[i][j] && !G[j][i]) {
                if (K < 2) ret.push_back(make_pair(i,j));
                K++;
            }

        printf("Case %d, ", id++);
        if (!K) puts("no concurrent events.");
        else {
            printf("%d concurrent events:\n", K);
            for (int i = 0; i < ret.size(); i++) {
                printf("(%s,%s) ", rmapa[ret[i].first].c_str(), rmapa[ret[i].second].c_str());
            }
            putchar('\n');
        }
    }

    return 0;
}
