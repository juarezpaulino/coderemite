/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

typedef long long i64;

int FIB[1600000];

void compute() {
    FIB[0] = FIB[1] = 1;
    for (int i = 2; i < 1600000; i++) FIB[i] = (FIB[i-1] + FIB[i-2])%1048576;
}

int main() {

    compute();

    int T;
    scanf("%d", &T);

    int N, M;
    while (T--) {
        scanf("%d %d", &N, &M);
        int M1 = 1<<M, M2 = M1 + (1<<(M-1));
        printf("%d\n", FIB[N%M2]%M1);
    }

    return 0;
}
