/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;


int main() {

    int p2, p3, p5, end;
    int A[1500];

    p2 = p3 = p5 = end = 0;

    A[end++] = 1;
    while (end < 1500) {
        while (A[p2] * 2 <= A[end-1]) p2++;
        while (A[p3] * 3 <= A[end-1]) p3++;
        while (A[p5] * 5 <= A[end-1]) p5++;
        if (A[p2] * 2 < A[p3] * 3) {
            if (A[p2] * 2 < A[p5] * 5)
                A[end++] = A[p2++] * 2;
            else
                A[end++] = A[p5++] * 5;
        }
        else {
            if (A[p3] * 3 < A[p5] * 5)
                A[end++] = A[p3++] * 3;
            else
                A[end++] = A[p5++] * 5;
        }
    }

    printf("The 1500'th ugly number is %d.\n", A[1499]);

    return 0;
}
