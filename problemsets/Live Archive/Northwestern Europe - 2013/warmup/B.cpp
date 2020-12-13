/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;


int main() {

    int C[110];
    int N;
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i <= 100; i++) C[i] = 0;
        for (int i = 0; i < N; i++) {
            int c;
            scanf("%d", &c);
            C[c]++;
        }
        int c = -1, best = 0, r = 0;
        for (int i = 0; i <= 100; i++) {
            if (C[i] > best) {
                best = C[i];
                c = i;
                r = 0;
            }
            else if (C[i] == best) r = 1;
        }
        if (c == -1 || r) printf("reelection\n");
        else printf("%d\n", c);
    }

    return 0;
}
