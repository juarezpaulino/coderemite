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

using namespace std;

char MAPA[500][500];
char V[500][500];
int H, W;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

pair<char,int> RET[30];

void DFS(int y, int x) {
    V[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i],
            nx = x+dx[i];
        if (ny >= H || nx >= W || ny < 0 || nx < 0 || V[ny][nx] || MAPA[ny][nx]!=MAPA[y][x]) continue;
        DFS(ny,nx);
    }
}

bool comp(const pair<char,int> &A, const pair<char,int> &B) {
    if (A.second != B.second) return A.second > B.second;
    return A.first < B.first;
}

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("World #%d\n", t);
        for (int i = 0; i < 26; i++) RET[i].first = 'a'+i, RET[i].second = 0;
        scanf("%d %d", &H, &W);
        for (int i = 0; i < H; i++) scanf("%s", MAPA[i]);
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) V[i][j] = 0;
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) if (!V[i][j]) {
            RET[MAPA[i][j]-'a'].second++;
            DFS(i,j);
        }
        sort(RET, RET+26, comp);
        for (int i = 0; RET[i].second && i < 26; i++) {
            printf("%c: %d\n", RET[i].first, RET[i].second);
        }
    }

    return 0;
}

