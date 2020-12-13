/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int N;
    int A, B, C;

    scanf("%d", &N);
    A = B = C = 0;
    for (int i = 0; i < N; i++) {
        int v1, v2;
        scanf("%d/%d", &v1, &v2);
        if (v1==3&&v2==4) A++;
        else if (v1==1&&v2==2) B++;
        else C++;
    }

    int ret = 1;

    if (A && C) { int v = min(A, C); ret += v; C -= v; A -= v; }
    if (A) ret += A;

    ret += B/2; B = B%2;
    if (B) { ret++; C -= 2; }

    if (C > 0) ret += (C + 3) / 4;

    printf("%d\n", ret);

    return 0;
}
