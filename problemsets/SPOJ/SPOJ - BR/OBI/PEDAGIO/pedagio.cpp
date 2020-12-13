/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <queue>

using namespace std;

int adj[51][2500], nadj[51];
int c, l, e, p;
char disc[51];


int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}

void bfs(int v) {
    register int i, x;
    queue<int> q;
    q.push(v); disc[v] = 0;
    while (!q.empty()) {
        v = q.front(); q.pop();
        if (disc[v]+1 > p) return;
        for (i = 0; i < nadj[v]; i++) if (adj[v][i] != l && !disc[adj[v][i]]) { 
            x = adj[v][i]; disc[x] = disc[v]+1; q.push(x);
        }
    }
}


int main() {

    register int i, k = 1, x, y;
    char sp;
    while (1) {
        c = get_int(); e = get_int(); l = get_int(); p = get_int();
        if (!c && !l && !e && !p) break;
        for (i = 1; i <= c; i++) nadj[i] = disc[i] = 0;
        for (i = 0; i < e; i++) { 
            x = get_int(); y = get_int(); adj[x][nadj[x]++] = y; adj[y][nadj[y]++] = x;
        }
        bfs(l);
        printf("Teste %d\n", k++);
        for (i = 1, sp = 0; i <= c; i++)
            if (disc[i]) {
                if (sp) printf(" %d", i);
                else { printf("%d", i); sp = 1; }
            }
        printf("\n\n");
    }
    
    return 0;
}

