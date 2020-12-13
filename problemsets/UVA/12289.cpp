/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

using namespace std;

int cmp(char *A, const char *B) {
    int ret = 0;
    for (int i = 0; A[i]; i++) if (A[i]!=B[i]) ret++;
    return ret;
}

int main() {

    int N;
    scanf("%d", &N);
    while (N--) {
        int ret;
        char A[100];
        scanf("%s", A);
        if (strlen(A)==5) puts("3");
        else if (cmp(A,"one")>=2) puts("2");
        else puts("1");
    }

    return 0;
}
