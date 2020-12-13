/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int N, T = 1;
    while (scanf("%d", &N) != EOF) {
        if (N < 0) break;
        int M[12], P[12];
        for (int i = 0; i < 12; i++) scanf("%d", M+i);
        for (int i = 0; i < 12; i++) scanf("%d", P+i);
        printf("Case %d:\n", T++);
        for (int i = 0; i < 12; i++) {
            if (N >= P[i]) puts("No problem! :D"), N-=P[i];
            else puts("No problem. :(");
            N += M[i];
        }
    }

    return 0;
}
