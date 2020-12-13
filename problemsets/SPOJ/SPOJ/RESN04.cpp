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

int T, N;

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int ret = 0;
        for (int i = 1; i <= N; i++) {
            int x; scanf("%d",&x);
            ret += x/i;
        }
        if (ret & 1) puts("ALICE");
        else puts("BOB");
    }

    return 0;
}
