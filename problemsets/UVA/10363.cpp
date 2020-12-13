/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char M[3][5];
int W[8], xw, ow, x, o;

void update(char c, int k) {
    if (c=='X') xw++, W[k] = -1;
    else if (c=='O') ow++, W[k] = 1;
    else W[k] = 0;
}

int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        bool ok = 1;
        ow = xw = o = x = 0;
        for (int i = 0; i < 3; i++) {
            gets(M[i]);
            for (int j = 0; j < 3; j++) if (M[i][j]=='X') x++; else if (M[i][j]=='O') o++;
        }
        int W[8];
        for (int i = 0; i < 3; i++) if (M[i][0]==M[i][1]&&M[i][1]==M[i][2]) update(M[i][0], i);
        for (int i = 0; i < 3; i++) if (M[0][i]==M[1][i]&&M[1][i]==M[2][i]) update(M[0][i], 3+i);
        if (M[0][0]==M[1][1]&&M[1][1]==M[2][2]) update(M[0][0], 6);
        if (M[0][2]==M[1][1]&&M[1][1]==M[2][0]) update(M[0][2], 7);
        if (xw==2 && ow==0) {
            if (x-o != 1) ok = 0;
            if ((W[0]==-1&&W[1]==-1) ||
                (W[0]==-1&&W[2]==-1) ||
                (W[1]==-1&&W[2]==-1) ||
                (W[4]==-1&&W[5]==-1) ||
                (W[3]==-1&&W[4]==-1) ||
                (W[3]==-1&&W[5]==-1)) ok = 0;
        }
        else if (xw==1 && ow==0) {
            if (x-o != 1) ok = 0;
        }
        else if (ow==1 && xw==0) {
            if (x-o != 0) ok = 0;
        }
        else if (xw==0 && ow==0) {
            if (x-o>1 || x-o<0) ok = 0;
        }
        else ok = 0;
        if (ok) puts("yes");
        else puts("no");
        gets(M[0]);
    }

    return 0;
}
