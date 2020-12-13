/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<char> C[30];
int c[30], V[30];

void dfs(int u) {
    V[u] = 1;
    for (int i = 0; i < C[u].size(); i++) {
        int v = C[u][i];
        if (!V[v]) dfs(v);
    }
}

int main() {

    int T, N;
    scanf("%d", &T);
    while (T--) {
        char S[101010];
        for (int i = 0; i < 30; i++) C[i].clear(), c[i] = 0, V[i] = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%s", S);
            int k = strlen(S);
            C[*S-'a'].push_back(S[k-1]-'a');
            C[S[k-1]-'a'].push_back(*S-'a');
            c[*S-'a']++; c[S[k-1]-'a']--;
        }
        int id = 0;
        for (int i = 0; i < 30; i++) if (!V[i] && C[i].size()) {
            dfs(i);
            id++;
        }
        int p = 0, n = 0;
        for (int i = 0; i < 30; i++) {
            if (!c[i]) continue;
            else if (c[i]==1) p++;
            else if (c[i]==-1) n++;
            else id = 0;
        }
        if (id==1 && ((p==1&&n==1) || !(p|n))) puts("Ordering is possible.");
        else puts("The door cannot be opened.");
    }

    return 0;
}
