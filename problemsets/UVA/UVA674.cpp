/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int C[] = { 1, 5, 10, 25, 50 };
int T[10000];

int main() {

    T[0] = 1;
    for (int j = 0; j < 5; j++) for (int i = 0; i+C[j] < 10000; i++) T[i+C[j]]+=T[i];

    int N;
    while (scanf("%d", &N) != EOF) {
        printf("%d\n", T[N]);
    }

    return 0;
}
