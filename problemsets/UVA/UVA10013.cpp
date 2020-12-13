/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

char C[1000000];

int N, M;

int main() {

    scanf("%d", &N);
    while (N--) {
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
             int a, b;
             scanf("%d %d", &a, &b);
             C[i] = a+b;
        }
        for (int i = M-1; i >= 0; i--) {
            C[i-1] += C[i]/10;
            C[i] = (C[i]%10) + '0';
        }
        C[M] = 0;
        puts(C);
        if (N) putchar('\n');
    }

    return 0;
}
