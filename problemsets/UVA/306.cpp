/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
///////////////////////////////////////////////////////////////////////////////
//
// Check cycle "for each position" in permutation instead for overall
// permutation.
//
// It will sum less than O(N*N).
//

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;


int P[300][300], Pi[300], OK[300];
int N, K;
char L[300], RET[300];

void process() {
    bool done = 0;
    while (!done) {
        done = 1;
        for (int i = 0; i < N; i++) if (!OK[i]) {
            P[Pi[i]][i] = P[Pi[i]-1][P[0][i]];
            if (P[Pi[i]][i] == P[0][i]) OK[i] = 1;
            else Pi[i]++, done = 0;
        }
    }
}

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) {
            scanf("%d", &P[0][i]); P[0][i]--;
            Pi[i] = 1; OK[i] = P[0][i]==i;
        }
        process();
        while (scanf("%d", &K)) {
            getchar(); if (!K) break;
            K--; gets(L); { int i; for (i = strlen(L); i < N; i++) L[i] = ' '; L[i] = 0; }
            RET[N] = 0;
            for (int i = 0; i < N; i++) RET[P[K%Pi[i]][i]] = L[i];
            puts(RET);
        }
        putchar('\n');
    }

    return 0;
}
