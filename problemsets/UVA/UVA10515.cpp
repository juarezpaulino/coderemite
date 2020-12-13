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

int RET[10][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {2, 4, 8, 6},
    {3, 9, 7, 1},
    {4, 6, 4, 6},
    {5, 5, 5, 5},
    {6, 6, 6, 6},
    {7, 9, 3, 1},
    {8, 4, 2, 6},
    {9, 1, 9, 1}
};

char A[200], B[200];

int main() {

    while (scanf("%s %s", A, B)) {
        if (!strcmp(A,"0") && !strcmp(B,"0")) break;
        if (!strcmp(B,"0")) { puts("1"); continue; }
        int M = A[strlen(A)-1]-'0',
            n = strlen(B),
            N = (n >= 2) ? B[n-2]*10+B[n-1]-2*'0' : B[n-1]-'0';
        if (N == 0) N = 100;
        int k = ((N-1)%20)+1;
        k = (k-1)%4;
        printf("%d\n", RET[M][k]);
    }

    return 0;
}
