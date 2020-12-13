/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int A[3];
    scanf("%d %d %d", A, A+1, A+2);
    sort(A, A+3);
    if (A[2] >= A[1]+A[0]) { puts("n"); return 0; }
    int d0 = A[0]*A[0];
    int d1 = A[1]*A[1];
    int d2 = A[2]*A[2];
    if (d0+d1 == d2) puts("r");
    else if (d0+d1 < d2 || d0+d2 < d1 || d1+d2 < d0) puts("o");
    else puts("a");

    return 0;
}
