/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;


int main() {

    int A[110], B[110];
    int N, D, R;
    while (scanf("%d %d %d", &N, &D, &R)) {
        if (!(N|D|R)) break;
        for (int i = 0; i < N; i++) scanf("%d", A+i);
        for (int i = 0; i < N; i++) scanf("%d", B+i);
        sort(A, A+N);
        sort(B, B+N, greater<int>());
        int ret = 0;
        for (int i = 0; i < N; i++) ret += (A[i]+B[i] > D) ? (A[i]+B[i]-D)*R : 0;
        printf("%d\n", ret);
    }

    return 0;
}
