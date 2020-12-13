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
#include <numeric>

using namespace std;

int N;

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        int M = (N+3)/4*4;
        printf("Printing order for %d pages:\n", N);
        for (int i = 1; i <= N && i <= M/2; i++) {
            printf("Sheet %d, %s: ", (i+1)/2, (i%2)?"front":"back ");
            if (i%2) {
                if (M-i+1 <= N) printf("%d, ", M-i+1);
                else printf("Blank, ");
                printf("%d\n", i);
            }
            else {
                printf("%d, ", i);
                if (M-i+1 <= N) printf("%d\n", M-i+1);
                else printf("Blank\n");
            }
        }
    }

    return 0;
}
