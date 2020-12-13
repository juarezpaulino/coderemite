/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>


using namespace std;

int count(int M) {
    int c = 1, d = 0, tot = 0, i, K;
    for (i = 1, K = M/10, d = 0; K; i++) {
        d += c*9;
        tot += c*9*i;
        c = c*10;
        K/=10;
    }
    tot += (M-d) * i;
    return tot;
}

int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        int a = 1, b = 20000000;
        while (a < b) {
            int m = (a+b)/2, c = count(m);
            if (c >= N) b = m;
            else a = m+1;
        }
        int mod = N-count(a-1);
        char S[10];
        sprintf(S, "%d", a);
        printf("%c\n", S[mod-1]);
    }


    return 0;
}
