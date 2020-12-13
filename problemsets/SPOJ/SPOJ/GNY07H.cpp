/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int T, W;
int DP[100];

int main() {

    int id = 1;
    DP[0] = 1; DP[1] = 1; DP[2] = 5; DP[3] = 11;
    for (int i = 4; ; i++) {
        DP[i] = DP[i-1] - DP[i-4] + 5*DP[i-2] + DP[i-3];
        if (DP[i]<0 || DP[i] > 0x3F3F3F3F) break;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &W);
        printf("%d %d\n", id, DP[W]);
        id++;
    }

    return 0;
}
