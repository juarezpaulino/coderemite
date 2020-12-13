/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int M, N, C, D;
char A[20], B[20];
int ret;

void go(int k) {
    if (k == M) {
        int c = 0, d = 0;
        int G[10] = {0}, H[10] = {0};
        for (int i = 0; i < M; i++) G[A[i]-'0']++;
        for (int i = 0; i < M; i++) {
            if (A[i]==B[i]) c++, G[B[i]-'0']--;
            else H[B[i]-'0']++;
        }
        for (int i = 1; i <= 9; i++) d += min(G[i], H[i]);
        if (c == C && d == D) {
            ret++;
        }
        return;
    }
    for (int i = 1; i <= 9; i++) {
        B[k] = '0'+i;
        go(k+1);
    }
}


int main() {

    scanf("%d", &N);
    while (N--) {
        scanf("%s %d %d", A, &C, &D);
        M = strlen(A);
        ret = 0;
        go(0);
        printf("%d\n", ret);
    }

    return 0;
}
