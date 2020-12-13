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

char R[1000001];

int T, N;

int main() {

    int cur = 0;
    int p = 1, pi = 1;
    for (int i = 1; i <= 1000000; i++) {
        if (pi > p) {
            p++; pi = 1; cur = (cur + 1) % 26;
        }
        R[i] = cur+'A';
        pi++;
    }

    int N;
    while (scanf("%d", &N) != EOF) {
        printf("TERM %d IS %c\n", N, R[N]);
    }

    return 0;
}
