/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int,int> PII;

int C[505][6];
PII RET[505][6];
int DP[505][6];
int N;

char S[6][101] = { "front", "left", "top", "bottom", "right", "back" };

int go(int b, int f) {
    int &ret = DP[b][f];
    if (ret != -1) return ret;
    RET[b][f] = PII(-1,-1);
    ret = 1;
    for (int i = b-1; i > 0; i--) {
        for (int j = 0; j < 6; j++) if (C[b][f]==C[i][j])
            if (go(i,5-j)+1 > ret)
                RET[b][f] = PII(i,5-j), ret = go(i,5-j)+1;
    }
    return ret;
}

void build_path(int b, int f) {
    if (RET[b][f].first == -1) {
        printf("%d %s\n", b, S[f]);
        return;
    }
    build_path(RET[b][f].first, RET[b][f].second);
    printf("%d %s\n", b, S[f]);
}

int main() {

    int T = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 1; i <= N; i++)
            scanf("%d%d%d%d%d%d", &C[i][0], &C[i][5], &C[i][1], &C[i][4], &C[i][2], &C[i][3]);
        memset(DP, -1, sizeof(DP));
        int ret = 0, b, f;
        for (int i = 1; i <= N; i++) for (int j = 0; j < 6; j++) if (go(i,j) > ret)
            b = i, f = j, ret = go(i,j);
        if (T != 1) putchar('\n');
        printf("Case #%d\n%d\n", T++, ret);
        build_path(b, f);
    }

    return 0;
}
