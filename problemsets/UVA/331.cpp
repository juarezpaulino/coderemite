/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int N, ret;
int V[5];

void go() {
    bool ok = 1;
    for (int i = 0; i < N-1; i++) if (V[i] > V[i+1]) {
        ok = 0;
        swap(V[i],V[i+1]);
        go();
        swap(V[i],V[i+1]);
    }
    if (ok) ret++;
}

int main() {

    int T = 1;
    while (scanf("%d", &N) != EOF) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        ret = 0;
        bool ok = 0;
        for (int i = 0; i < N-1; i++) if (V[i] > V[i+1]) ok = 1;
        if (ok) go();
        printf("There are %d swap maps for input data set %d.\n", ret, T++);
    }

    return 0;
}
