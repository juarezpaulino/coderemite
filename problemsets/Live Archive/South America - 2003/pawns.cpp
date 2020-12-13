/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <queue>

using namespace std;


int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

struct st { int h, k, d; char live[8], pw[8]; };

int p, pw[8], h;
int adj[8] = {-10, -17, -15, -6, 6, 15, 17, 10};

int bfs() {
    queue<st> q;
    st v, x;
    int i, j, f;
    v.h = h; v.k = 0; v.d = 0;
    for (i = 0; i < p; i++) v.live[i] = 1, v.pw[i] = pw[i];
    q.push(v);
    while (!q.empty()) {
        v = q.front(); q.pop(); if (v.k==p) return v.d;
        for (i = 0; i < 8; i++) {
            x=v; x.h+=adj[i]; x.d++;
            if (x.h >= 1 && x.h <= 64 && (abs(((x.h-1)%8)-((v.h-1)%8))+abs(((x.h-1)/8)-((v.h-1)/8))==3)) {
                for (j = 0, f = 1; f && j < p; j++) if (x.live[j]) {
                    if (x.pw[j]==x.h) { x.k++; x.live[j]=0; continue; }
                    x.pw[j]+=8; if (x.pw[j]==x.h || x.pw[j]>64) f = 0;
                }
                if (f) q.push(x);
            }
        }
    }
    return -1;
}


int main() {
    int i;
    for (; p = get_int(), p; ) {
        for (i = 0; i < p; i++) pw[i] = get_int(); h = get_int();
        if ((i = bfs())!=-1) printf("%d\n", i); else printf("impossible\n");
    }
    
    return 0;
}
