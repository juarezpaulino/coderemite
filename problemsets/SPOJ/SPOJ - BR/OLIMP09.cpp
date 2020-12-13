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
    int o, p, b, i;
    triple(int o = 0, int p = 0, int b = 0, int i = 0) : o(o), p(p), b(b), i(i) {}
    bool operator<(const triple &B) const {
        if (o != B.o) return o > B.o;
        if (p != B.p) return p > B.p;
        if (b != B.b) return b > B.b;
        return i < B.i;
    }
};

triple V[110];


int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) V[i] = triple(0,0,0,i+1);
    while (M--) {
        int o, p, b;
        scanf("%d %d %d", &o, &p, &b);
        V[o-1].o++;
        V[p-1].p++;
        V[b-1].b++;
    }
    sort(V, V+N);
    printf("%d", V[0].i);
    for (int i = 1; i < N; i++) printf(" %d", V[i].i);
    putchar('\n');

    return 0;
}
