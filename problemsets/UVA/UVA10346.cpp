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

    int N, K, B;
    while (scanf("%d %d", &N, &K) != EOF) {
        int ret = 0; B = 0;
        while (N) {
            ret += N;
            B += N;
            N = B / K;
            B %= K;
        }
        printf("%d\n", ret);
    }

    return 0;
}
