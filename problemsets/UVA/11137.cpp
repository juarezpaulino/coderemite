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

using namespace std;

long long way[10101];

int main() {

    int C[22];
    for (int i = 0; i < 21; i++) C[i] = (i+1)*(i+1)*(i+1);

    way[0] = 1;
    for (int i = 0; i < 21; i++) for (int v = C[i]; v <= 10000; v++) way[v] += way[v-C[i]];
    int N;
    while (scanf("%d", &N) != EOF) printf("%lld\n", way[N]);

    return 0;
}
