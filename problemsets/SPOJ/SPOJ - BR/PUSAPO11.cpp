/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main(){

    int N, M;
    scanf("%d %d", &N, &M);
    int V[101] = {0};
    for (int i = 0; i < M; i++) {
        int P, D;
        scanf("%d %d", &P, &D);
        V[P] = 1;
        for (int p = P-D; p > 0; p-=D) V[p] = 1;
        for (int p = P+D; p <= N; p+=D) V[p] = 1;
    }
    for (int i = 1; i <= N; i++) printf("%d\n", V[i]);

    return 0;
}
