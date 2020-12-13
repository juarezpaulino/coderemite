/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int N, V[10] = {0};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x; char c;
        scanf("%d %c", &x, &c);
        if (c == '*') V[x]++; else V[x]--;
    }
    V[3] += V[9]*2;
    V[2] += V[8]*3;
    V[2] += V[4]*2;
    V[2] += V[6];
    V[3] += V[6];
    long long num = 1, den = 1;
    while (V[2]>0) num *= 2, V[2]--; while (V[2]<0) den *= V[2], V[2]++;
    while (V[3]>0) num *= 3, V[3]--; while (V[3]<0) den *= V[3], V[3]++;
    while (V[5]>0) num *= 5, V[5]--; while (V[5]<0) den *= V[5], V[5]++;
    while (V[7]>0) num *= 7, V[7]--; while (V[7]<0) den *= V[7], V[7]++;
    printf("%lld\n", num / den);

    return 0;
}
