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

int ry[] = {1, 3, 4, 2};
int rx[] = {0, 1, 5, 4};
int rz[] = {0, 2, 5, 3};

int main() {

    char S[20];
    while (gets(S)) {
        string A, B;
        for (int i = 0; i < 6; i++) A += S[i];
        for (int i = 6; i < 12; i++) B += S[i];
        if (A == B) { puts("TRUE"); goto OUT; }
        for (int k = 0; k < 4; k++) for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
            string C = A, D = A;
            for (int c = 0; c < k; c++) {
                for (int l = 0; l < 4; l++) D[rz[(l+1)%4]] = C[rz[l]];
                C = D;
            }
            for (int c = 0; c < i; c++) {
                for (int l = 0; l < 4; l++) D[ry[(l+1)%4]] = C[ry[l]];
                C = D;
            }
            for (int c = 0; c < j; c++) {
                for (int l = 0; l < 4; l++) D[rx[(l+1)%4]] = C[rx[l]];
                C = D;
            }
            if (C == B) { puts("TRUE"); goto OUT; }
        }
        puts("FALSE");
OUT:;
    }

    return 0;
}
