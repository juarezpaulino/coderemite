/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

long long DP[30100];
int C[] = { 1, 5, 10, 25, 50 };
int N;

int main() {

    DP[0] = 1;
    for (int i = 0; i < 5; i++) for (int j = C[i]; j <= 30000; j++)
        DP[j] += DP[j-C[i]];

    while (scanf("%d", &N) != EOF) {
        if (DP[N]==1) printf("There is only 1 way to produce %d cents change.\n", N);
        else printf("There are %lld ways to produce %d cents change.\n", DP[N], N);
    }

    return 0;
}
