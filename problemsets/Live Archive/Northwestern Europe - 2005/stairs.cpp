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
    
    int T, N, F, B, b, c[2323];

    for (scanf("%d", &T); scanf("%d%d%d", &N, &F, &B), B--, T--; ) {
        
        for (int i = 0; i < N && scanf("%d%d",c+i, &b); ++i) c[i] += 2*b*(F-c[i]);
        
        nth_element(c, c+B%N, c+N);
        printf("%d\n", B/N*2*F+F+c[B%N]);
    }
}
