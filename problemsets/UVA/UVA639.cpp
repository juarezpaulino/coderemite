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

char MAPA[4][10];
int N, ret;

void go(int y, int x, int p) {
    if (x == N) { go(y+1, 0, p); return; }
    if (y == N) { ret = max(ret, p); return; }
    if (p + N-x + N*N - N*y <= ret) return;
    if (MAPA[y][x]=='X') { go(y, x+1, p); return; }

    // To put or not to put. That's the question.
    bool ok = true;
    for (int i = y-1; i >= 0; i--) {
        if (MAPA[i][x]=='X') break;
        if (MAPA[i][x]=='r') { ok = false; break; }
    }
    for (int j = x-1; j >= 0 && ok; j--) {
        if (MAPA[y][j]=='X') break;
        if (MAPA[y][j]=='r') { ok = false; break; }
    }
    if (ok) {
        MAPA[y][x] = 'r';
        go(y, x+1, p+1);
        MAPA[y][x] = '.';
    }

    go(y, x+1, p);
}

int main() {

    while(scanf("%d ", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) gets(MAPA[i]);
        ret = 0;
        go(0,0,0);
        printf("%d\n", ret);
    }
    return 0;
}
