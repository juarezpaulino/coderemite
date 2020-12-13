/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(M, v) memset(M, v, sizeof(M))


int ADJ[300][300];
int N, T;

void add(int A, int B) {
    if (ADJ[A][B]) return;

    ADJ[A][B] = 1;

    for (int k = 0; k <= N; k++)
        if (ADJ[B][k])
            add(A, k);

    for (int k = 0; k <= N; k++)
        if (ADJ[k][A])
            add(k, B);
}

int main() {

    int id = 1;
    while (1) {
        scanf("%d %d", &N, &T);
        if (!N && !T) break;
        CLR(ADJ,0);
        int ret = 0;
        for (int i = 0; i < T; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            if (A==B || ADJ[B][A]) ret++;
            else add(A,B);
        }
        printf("%d. %d\n", id++, ret);
    }

    return 0;
}
