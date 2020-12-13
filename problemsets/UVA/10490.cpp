/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long P[50];

int main() {

    P[2] = 6;
    P[3] = 28;
    P[5] = 496;
    P[7] = 8128;
    P[11] = -1;
    P[13] = 33550336;
    P[17] = 8589869056LL;
    P[19] = 137438691328LL;
    P[23] = -1;
    P[29] = -1;
    P[31] = 2305843008139952128;
    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        if (!P[N]) puts("Given number is NOT prime! NO perfect number is available.");
        else if (P[N]==-1) puts("Given number is prime. But, NO perfect number is available.");
        else printf("Perfect: %lld!\n", P[N]);
    }

    return 0;
}
