/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

typedef pair<int,int> PII;


char S[101];

int dy[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dx[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int t = (16<<15) + (24<<10) + (30<<5) + 31 + (2<<25) + (2<<28);

int main() {

    int T;
    gets(S); sscanf(S, "%d", &T);
    while (T--) {
        int s = 0;
        for (int i = 0; i < 5; i++) {
            gets(S);
            for (int j = 0; j < 5; j++) {
                if (S[j]==' ') s |= (i<<25) | (j<<28);
                else if (S[j]=='1') s |= 1<<(i*5+j);
            }
        }
        map<int, int> dist;
        priority_queue<PII> q;
        q.push(PII(-0, s));
        dist[s] = 0;
        bool ok = 0;
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (u == t) { ok = 1; break; }
            int d = dist[u];
            if (d >= 10) continue;
            int y = (u>>25)&7, x = (u>>28)&7;
            for (int i = 0; i < 8; i++) {
                int ny = y+dy[i], nx = x+dx[i];
                if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
                int v = u;
                v &= ~(63<<25); v |= (ny<<25) | (nx<<28);
                if (u & (1<<(ny*5+nx)))
                if (u & (1<<(ny*5+nx)))
                    v = v & ~(1<<(ny*5+nx)) | (1<<(y*5+x));
                if (dist.count(v)) continue;
                int d2 = dist[v] = d+1;
                if (v == t) { ok = 1; goto OUT; }
                q.push(PII(-(d2*3 + 2*(__builtin_popcount(v&u))), v));
            }
        }
OUT:
        if (!ok) puts("Unsolvable in less than 11 move(s).");
        else printf("Solvable in %d move(s).\n", dist[t]);
    }

    return 0;
}
