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

int A[7];

int main() {

    while (scanf("%d %d %d %d %d %d", A+1, A+2, A+3, A+4, A+5, A+6)) {
        if (!(A[1]|A[2]|A[3]|A[4]|A[5]|A[6])) break;
        int ret = 0;

        // Solve for 6x6.
        ret += A[6];

        // Solve for 5x5.
        ret += A[5];
        A[1] -= 11*A[5];

        // Solve for 4x4.
        ret += A[4];
        A[2] -= 5*A[4];
        if (A[2] < 0) A[1] -= abs(A[2])*4, A[2] = 0;

        // Solve for 3x3.
        ret += A[3]/4; A[3]%=4;
        if (A[3]) {
            ret++;
            if (A[3]==1) A[2]-=5, A[1] -= (A[2] < 0) ? abs(A[2])*4 + 16 : 16;
            if (A[3]==2) A[2]-=3, A[1] -= (A[2] < 0) ? abs(A[2])*4 + 6 : 6;
            if (A[3]==3) A[2]-=1, A[1] -= (A[2] < 0) ? abs(A[2])*4 + 5 : 5;
        }

        // Solve for 2x2.
        if (A[2] > 0){
            ret += A[2]/9; A[2]%=9;
            if (A[2]) {
                ret++;
                A[1]-=36-A[2]*4;
            }
        }

        // Solve for 1x1.
        if (A[1] > 0) ret += (A[1]+35)/36;

        printf("%d\n", ret);
    }

    return 0;
}
