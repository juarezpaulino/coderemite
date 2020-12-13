/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int A[4];
        scanf("%d %d %d %d", A, A+1, A+2, A+3);
        sort(A, A+4);
        if (A[0]==A[1]&&A[1]==A[2]&&A[2]==A[3]) puts("square");
        else if (A[0]==A[1]&&A[1]!=A[2]&&A[2]==A[3]) puts("rectangle");
        else if (A[0]+A[1]+A[2]>A[3]) puts("quadrangle");
        else puts("banana");
    }

    return 0;
}
