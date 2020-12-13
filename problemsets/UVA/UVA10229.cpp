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

typedef long long i64;

int N, M;

i64 MOD;

struct mat { i64 V[2][2]; };

mat MUL(mat A, mat B) {
    mat C;
    memset(C.V, 0, sizeof(C.V));
    for (int k = 0; k < 2; k++) for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
        C.V[k][j] = (C.V[k][j] + (A.V[k][i]*B.V[i][j]) % MOD) % MOD;
    return C;
}

mat POW(mat A, int N) {
    mat R;
    if (N==0) {
        memset(R.V, 0, sizeof(R.V));
        for (int i = 0; i < 2; i++) R.V[i][i] = 1LL;
        return R;
    }
    R = POW(A, N/2);
    R = MUL(R,R);
    if (N%2) R = MUL(R, A);
    return R;
}


int main() {

    while (scanf("%d %d", &N, &M) != EOF) {
        if (N == 0) { puts("0"); continue; }
        MOD = 1LL<<M;
        mat A = { 0, 1, 1, 1 };
        A = POW(A, N-1);
        printf("%lld\n", A.V[1][1]);
    }

    return 0;
}
