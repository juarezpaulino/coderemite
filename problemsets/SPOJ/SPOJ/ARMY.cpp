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

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int N, M;
        cin >> N >> M;
        int A = -1, B = -1;
        for (int i = 0; i < N; i++) { int x; scanf("%d", &x); A = max(A, x); }
        for (int i = 0; i < M; i++) { int x; scanf("%d", &x); B = max(B, x); }
        if (A >= B) puts("Godzilla");
        else puts("MechaGodzilla");
    }

    return 0;
}
