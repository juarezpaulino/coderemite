/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {

    int D, N;
    int A, B;

    while (scanf("%d", &N)!=EOF) {
        D = (sqrt(1 + 8 * N) + 1) / 2. - 1E-10;
        int R = D*(D+1)/2 - N;
        if (D%2==0) A = D-R, B = R+1;
        else  A = R+1, B = D-R;
        printf("TERM %d IS %d/%d\n", N, A, B);
    }

    return 0;
}
