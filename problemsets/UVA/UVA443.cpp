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
#include <queue>

using namespace std;

int N;
int R[6000];
char suf[10][10] = {
    "th",
    "st",
    "nd",
    "rd",
    "th",
    "th",
    "th",
    "th",
    "th",
    "th",
};

int main() {

    int p[4] = {1, 1, 1, 1}, v[] = {2, 3, 5, 7};
    int k = 0;
    R[++k] = 1;
    while (k <= 5842) {
        for (int j = 0; j < 4; j++)
            while (R[p[j]]*v[j] <= R[k]) p[j]++;
        int b = 0, l = R[p[0]]*v[0];
        for (int i = 1; i < 4; i++) if (R[p[i]]*v[i] < l) b = i, l = R[p[i]]*v[i];
        R[++k] = l; p[b]++;
    }

    while (scanf("%d", &N)) {
        if (!N) break;
        printf("The %d%s humble number is %d.\n", N, (N%100>10&&N%100<20)?"th":suf[N%10], R[N]);
    }

    return 0;
}
