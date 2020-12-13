/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

char S[1000];
char V[30];

int N, M;
char C[50][2];
bool VIS[300];
char RET[30];

void go(int k) {
    if (k == N) {
        RET[k] = 0;
        puts(RET);
        return;
    }
    for (int i = 0; i < N; i++) if (!VIS[V[i]]) {
        bool ok = true;
        for (int j = 0; j < M; j++) if (C[j][1]==V[i] && !VIS[C[j][0]]) {
            ok = false;
            break;
        }
        if (ok) {
            RET[k] = V[i];
            VIS[V[i]] = 1;
            go(k+1);
            VIS[V[i]] = 0;
        }
    }
}

int main() {

    bool f = false;
    while (gets(S)) {
        if (f) putchar('\n');
        f = true;
        N = 0;
        for (int i = 0; S[i]; i++) if (S[i]>='a'&&S[i]<='z') V[N++] = S[i];
        sort(V, V+N);
        gets(S);
        char a[2];
        int k = 0;
        M = 0;
        for (int i = 0; S[i]; i++) if (S[i]>='a'&&S[i]<='z') {
            a[k++] = S[i];
            if (k == 2) {
                C[M][0] = a[0];
                C[M++][1] = a[1];
                k = 0;
            }
        }
        go(0);
    }

    return 0;
}
