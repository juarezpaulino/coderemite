/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int M, N;
char MAPA[55][55];
int ret;

bool cmp(const pair<char,int> &A, const pair<char,int> &B) {
    if (A.second != B.second) return A.second > B.second;
    return A.first < B.first;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int y, int x, char c) {
    MAPA[y][x] = 0;
    ret++;
    for (int k = 0; k < 4; k++) {
        int ny = y+dy[k], nx = x+dx[k];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N || MAPA[ny][nx]!=c) continue;
        dfs(ny,nx,c);
    }
}

int main() {

    int id = 1;
    while (scanf("%d %d", &M, &N)) {
        if (!(M|N)) break;
        for (int i = 0; i < M; i++) scanf("%s", MAPA[i]);
        vector<pair<char,int> > RET;
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if (MAPA[i][j]>='A' && MAPA[i][j]<='Z') {
            ret = 0;
            char c = MAPA[i][j];
            dfs(i,j,c);
            RET.push_back(make_pair(c,ret));
        }
        sort(RET.begin(), RET.end(), cmp);
        printf("Problem %d:\n", id++);
        for (int i = 0; i < RET.size(); i++) printf("%c %d\n", RET[i].first, RET[i].second);
    }

    return 0;
}
