/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int mergecount(vector<int> &A) {
    int i, j, k;
    int N = A.size();
    if (N <= 1) return 0;
    vector<int> B(A.begin(), A.begin() + N/2),
                C(A.begin() + N/2, A.end());
    int ret = mergecount(B) + mergecount(C);
    for (i = j = k = 0; i < N; i++) {
        if (k == C.size()) A[i] = B[j++];
        else if (j == B.size()) A[i] = C[k++];
        else if (B[j] <= C[k]) A[i] = B[j++];
        else A[i] = C[k++], ret += N/2 - j;
    }
    return ret;
}

int main() {

    int N, M[1000];

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) scanf("%d", M+i);
        vector<int> A(M, M+N);
        int ret = mergecount(A);
        printf("Minimum exchange operations : %d\n", ret);
    }

    return 0;
}
