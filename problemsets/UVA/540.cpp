/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int fila[1010101];

int main() {

    int T;
    int S = 1;
    while (scanf("%d", &T)) {
        if (!T) break;
        for (int t = 0; t < T; t++) {
            int m, x;
            scanf("%d", &m);
            for (int i = 0; i < m; i++) {
                scanf("%d", &x);
                fila[x] = t;
            }
        }
        printf("Scenario #%d\n", S++);
        queue<int> G;
        queue<int> F[1010];
        char cmd[101];
        while (scanf("%s", cmd)) {
            if (cmd == string("ENQUEUE")) {
                int x;
                scanf("%d", &x);
                int f = fila[x];
                if (F[f].empty()) G.push(f);
                F[f].push(x);
            } else if (cmd == string("DEQUEUE")) {
                int f = G.front();
                int x = F[f].front();
                F[f].pop();
                if (F[f].empty()) G.pop();
                printf("%d\n", x);
            } else {
                break;
            }
        }
        putchar('\n');
    }

    return 0;
}
