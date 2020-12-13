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

int N;
int A[100];

int mergecount(vector<int> &A) {
    int ret = 0;
    int N = A.size();
    if (N <= 1) return 0;
    vector<int> B(A.begin(), A.begin() + N/2);
    vector<int> C(A.begin() + N/2, A.end());
    ret += mergecount(B);
    ret += mergecount(C);
    int i, j, k;
    for (i = j = k = 0; i < N; i++) {
        if (k == C.size()) A[i] = B[j++];
        else if (j == B.size()) A[i] = C[k++];
        else if (B[j] <= C[k]) A[i] = B[j++];
        else A[i] = C[k++], ret += N/2-j;
    }
    return ret;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", A+i);
        vector<int> B(A, A+N);
        int ret = mergecount(B);
        printf("Optimal train swapping takes %d swaps.\n", ret);
    }

    return 0;
}
