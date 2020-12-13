/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    int l = 0, x;
    bool ok = 1;
    for (int i = 0; ok && i < N; i++) {
        scanf("%d", &x);
        if (x - l > M) ok = 0;
        l = x;
    }
    if (42195 - l > M) ok = 0;
    if (ok) puts("S");
    else puts("N");

    return 0;
}
