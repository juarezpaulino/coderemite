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
    while (scanf("%d", &N) != EOF) {
        int ret = 0;
        while (N) ret++, N/=2;
        printf("%d\n", ret);
    }

    return 0;
}
