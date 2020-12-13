/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

    int T = 1;
    int N;
    int H[50];
    while (scanf("%d", &N)) {
        if (N == 0) break;
        int m = 0;
        for (int i = 0; i < N; i++) scanf("%d", H+i), m += H[i];
        m /= N;
        int ret = 0;
        for (int i = 0; i < N; i++) ret += abs(H[i]-m);
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", T++, ret>>1);
    }

    return 0;
}
