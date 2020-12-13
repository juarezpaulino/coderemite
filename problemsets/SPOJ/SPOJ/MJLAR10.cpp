/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int A[3], B[2], ord[3];

int main() {

    while (1) {
        scanf("%d %d %d %d %d", A, A+1, A+2, B, B+1);
        if (!A[0] && !A[1] && !A[2] && !B[0] && !B[1]) break;
        ord[0] = 0; ord[1] = 1; ord[2] = 2;
        int C = -1;
        for (int c = 1; c <= 52 && C==-1; c++) if (A[0]!=c && A[1]!=c && A[2]!=c && B[0]!=c && B[1]!=c) {
            int m = 3;
            do {
                int w = (A[ord[0]]<B[0]) + (A[ord[1]]<B[1]) + (A[ord[2]]<c);
                if (w < m) m = w;
            } while (next_permutation(ord, ord+3));
            if (m >= 2) C = c;
        }
        printf("%d\n", C);
    }

    return 0;
}
