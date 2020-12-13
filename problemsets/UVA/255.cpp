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

    int A, B, C;
    while (scanf("%d %d %d", &A, &B, &C) != EOF) {
        int rA = A/8, cA = A%8,
            rB = B/8, cB = B%8,
            rC = C/8, cC = C%8;
        if (A==B) puts("Illegal state");
        else if (rB!=rC && cB!=cC) puts("Illegal move");
        else if (rA==rB && rB==rC && (cA-cB)*(cA-cC) < 0) puts("Illegal move");
        else if (cA==cB && cB==cC && (rA-rB)*(rA-rC) < 0) puts("Illegal move");
        else if (A==C || B==C) puts("Illegal move");
        else if (abs(rA-rC) + abs(cA-cC) <= 1) puts("Move not allowed");
        else if ((A==0&&C==9) || (A==7&&C==14) || (A==56&&C==49) || (A==63&&C==54)) puts("Stop");
        else puts("Continue");
    }

    return 0;
}
