/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int sy, sx;
int ty, tx;
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
int B[40][40][4], vis[40][40], id = 1;
long long DP[40][40];

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch==EOF) return ch;
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}

long long go(int y, int x) {
    if (vis[y][x]==id) return DP[y][x];
    long long &ret = DP[y][x];
    vis[y][x] = id;
    if (y==ty && x==tx) return ret = 1;
    ret = 0;
    for (int i = 0; i < 2; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
        if (B[y][x][i]==id || B[ny][nx][(i+2)%4]==id) continue;
        ret += go(ny,nx);
    }
    return ret;
}


int main() {

    int T = get_int();
    while (T--) {
        N = get_int();
        sx = get_int(); sy = get_int();
        tx = get_int(); ty = get_int();
        int W = get_int();
        while (W--) {
            int x = get_int();
            int y = get_int();
            char d; scanf(" %c", &d);
            if (d=='N') B[y][x][0] = id;
            else if (d=='W') B[y][x][3] = id;
            else if (d=='S') B[y][x][2] = id;
            else if (d=='E') B[y][x][1] = id;
        }
        long long ret = go(sy,sx);
        printf("%lld\n", ret);
        id++;
    }

    return 0;
}
