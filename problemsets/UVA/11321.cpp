/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int V[101010];

bool comp(const int &A, const int &B) {
    int a = A%M, b = B%M;
    if (a != b) return a < b;
    if (abs(A%2) != abs(B%2)) return A%2;
    if (A%2) return A > B;
    return A < B;
}

int main() {

    while (scanf("%d %d", &N, &M)) {
        printf("%d %d\n", N, M);
        if (!(N|M)) break;
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        sort(V, V+N, comp);
        for (int i = 0; i < N; i++) printf("%d\n", V[i]);
    }

    return 0;
}
