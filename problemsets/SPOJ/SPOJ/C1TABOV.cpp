/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N;
int A[1010], B[1010];

int solve(int i, int j) {
    if (i > j) return 0;
    int p = i;
    for (int k = i+1; k <= j; k++)
        if (abs(A[k]) < abs(A[p]))
            p = k;
    int w = A[p];
    for (int k = i; k <= j; k++) A[k] -= w;
    return abs(w) + solve(i,p-1) + solve(p+1, j);
}


int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", A+i);
    for (int i = 0; i < N; i++) scanf("%d", B+i);
    for (int i = 0; i < N; i++) A[i] = B[i]-A[i];

    int ret = 0;

    for (int i = 0, j; i < N; i = j) {
        for (j = i; j < N && A[i]*A[j] >= 0; j++);
        ret += solve(i,j-1);
    }

    printf("%d\n", ret);

    return 0;
}
