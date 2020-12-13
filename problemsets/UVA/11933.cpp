/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        int A[2] = {0}, m = 0;
        int l = 0;
        while (N) {
            if (N&1) A[m] |= (1<<l), m = 1-m;
            l++;
            N >>= 1;
        }
        printf("%d %d\n", A[0], A[1]);
    }

    return 0;
}
