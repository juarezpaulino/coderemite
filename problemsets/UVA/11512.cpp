/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 1010101;
const int MAXD = 4;

string RET; int ret;
char S[1010];
char D[128], *RD = "ACGT";
int to[MAXN][MAXD], count[MAXN], last;

// Clear trie node pointer.
void clear(int u) {
    count[u] = 0;
    for (int i = 0; i < MAXD; i++) to[u][i] = -1;
}

// Add node by running word from root until reach some leaf.
void add(int u, const char *W) {
    count[u]++;
    while (*W) {
        int i = D[*W];
        if (to[u][i]==-1) clear(to[u][i] = ++last);
        u = to[u][i];
        count[u]++;
        W++;
	}
}

void dfs(int k, int u) {
    if (u==-1) return;
    if (count[u] >= 2 && k > RET.size()) { ret = count[u]; S[k] = 0; RET = S; }
    for (int i = 0; i < 4; i++) {
        S[k] = RD[i];
        dfs(k+1, to[u][i]);
    }
}

int main() {

    D['A'] = 0; D['C'] = 1; D['G'] = 2; D['T'] = 3;
    int T;
    scanf("%d", &T);
    while (T--) {
        last = 0;
        clear(0);
        scanf("%s", S); string s = S;
        for (int i = 0; i < s.size(); i++) add(0, s.substr(i).c_str());
        ret = 0; RET = ""; dfs(0,0);
        if (ret == 0) puts("No repetitions found!");
        else printf("%s %d\n", RET.c_str(), ret);
    }

    return 0;
}
