/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

#define ALL(M) (M).begin(), (M).end()
#define SORT(M) sort(ALL(M))
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())

using namespace std;

typedef vector<int> VI;

int main() {

    int N, K, S;

    scanf("%d %d %d", &N, &K, &S); K *= S;

    VI A; A.resize(N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    sort(ALL(A), greater<int>());
    int k = 0;
    while (K > 0) {
        K -= A[k]; k++;
    }
    printf("%d\n", k);

    return 0;
}
