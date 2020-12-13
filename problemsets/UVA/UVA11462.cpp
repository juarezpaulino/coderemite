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

void counting_sort(int A[], int B[], int N) {
    int maxv = *max_element(A, A+N);
    int C[maxv+1];
    for (int i = 0; i <= maxv; i++) C[i] = 0;
    for (int i = 0; i < N; i++) C[A[i]]++;
    for (int i = 1; i <= maxv; i++) C[i] += C[i-1];
    for (int i = N-1; i >= 0; i--) B[--C[A[i]]] = A[i];
}

int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        int A[N], B[N];
        for (int i = 0; i < N; i++) scanf("%d", A+i);
        counting_sort(A, B, N);
        printf("%d", B[0]);
        for (int i = 1; i < N; i++) printf(" %d", B[i]);
        putchar('\n');
    }

    return 0;
}
