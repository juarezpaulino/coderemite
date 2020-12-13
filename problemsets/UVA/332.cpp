/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const double EPS = 1E-10;

int main() {

    int j;
    int id = 1;
    while (scanf("%d", &j)) {
        if (j==-1) break;
        char S[101];
        scanf("%s", S);
        int X, A;
        int k = strlen(S)-2-j;
        sscanf(S+2, "%d", &X);
        S[2+k] = 0;
        sscanf(S+2, "%d", &A);
        if (k == 0) A = 0;
        int num = X - ((j == 0) ? 0 : A), den = 1;
        int B = 1;
        for (int i = 0; i < k+j; i++) {
            den *= 10;
            if (i < k) B *= 10;
        }
        if (j!=0) den -= B;
        int d = (num==0||den==0) ? 1 : __gcd(num,den);
        if (num == 0) den = 1;
        printf("Case %d: %d/%d\n", id++, num/d, den/d);
    }

    return 0;
}
