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

int T;
int N;
char MAPA[100][110];
map<pair<int,int>, int> DP;

const int MOD = 1000007;

int dy[] = { -1, -1, -2, -2 };
int dx[] = { -1, 1, -2, 2 };

int go(int y, int x) {
    if (y == 0) return 1;
    pair<int,int> u(y,x);
    if (DP.count(u)) return DP[u];
    int &ret = DP[u];
    ret = 0;
    for (int i = 0; i < 2; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (MAPA[ny][nx]!='B') ret = (ret + go(ny,nx)) % MOD;
        else {
            ny = y+dy[i+2], nx = x+dx[i+2];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N || MAPA[ny][nx]=='B') continue;
            ret = (ret + go(ny,nx)) % MOD;
        }
    }
    return ret;
}

int main() {

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        int y, x;
        for (int i = 0; i < N; i++) {
            scanf("%s", MAPA[i]);
            for (int j = 0; j < N; j++) if (MAPA[i][j]=='W') y = i, x = j;
        }
        DP.clear();
        int ret = go(y,x);
        printf("Case %d: %d\n", t, ret);
    }

    return 0;
}
