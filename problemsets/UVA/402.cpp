/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <list>

using namespace std;

int N, X;
int D[22];
int T = 1;

int josephus(int N) {
    int V[101], L = 0;

    for (int i = 0; i < N; i++) V[i] = i+1;

    while (L < 20 && N > X) {
        int k = 0, M = N;
        for (int i = 0; i < N; i++) {
            if (M > X && i%D[L]==D[L]-1) { M--; continue; }
            V[k++] = V[i];
        }
        N = k; L++;
    }

    printf("Selection #%d\n", T++);
    for (int i = 0; i < N; i++) {
        if (i) printf(" %d", V[i]);
        else printf("%d", V[i]);
    }
    putchar('\n');
    putchar('\n');
}


int main() {

    while (scanf("%d %d", &N, &X) != EOF) {
        for (int i = 0; i < 20; i++) scanf("%d", D+i);
        josephus(N);
    }
}
