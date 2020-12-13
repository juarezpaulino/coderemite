/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int M, N;

int main() {

    while (scanf("%d %d", &M, &N) != EOF) {
        if (M+N==0) break;
        int ret;
        if (M == 1 || N == 1) ret = max(M, N);
        else if (M == 2 || N == 2) ret = (M*N) / 8 * 4 + min((M*N)%8, 4);
        else ret = (M*N+1)/2;
        printf("%d knights may be placed on a %d row %d column board.\n", ret, M, N);
    }

    return 0;
}
