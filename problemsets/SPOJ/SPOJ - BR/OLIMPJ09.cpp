/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

struct triple {
    int n, i;
    triple(int n = 0, int i = 0) : n(n), i(i) {}
    bool operator<(const triple &B) const {
        if (n != B.n) return n > B.n;
        return i < B.i;
    }
};

triple V[110];


int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) V[i] = triple(0,i+1);
    while (M--) {
        int o, p, b;
        scanf("%d %d %d", &o, &p, &b);
        V[o-1].n++;
        V[p-1].n++;
        V[b-1].n++;
    }
    sort(V, V+N);
    printf("%d", V[0].i);
    for (int i = 1; i < N; i++) printf(" %d", V[i].i);
    putchar('\n');

    return 0;
}
