/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


short M[1510][1510];
int X[30], Y[30], L[30], C[30];
int id = 1;
int dx[] = { -1, 0, 1, 0};
int dy[] = { 0, -1, 0, 1};

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {

    int N;
    while (N = get_int()) {
        int A = 0, P = 0;
        for (int i = 0; i < N; i++) {
            X[i] = get_int()+1;
            Y[i] = get_int()+1;
            L[i] = get_int();
            C[i] = get_int();
//            scanf("%d %d %d %d", X+i, Y+i, L+i, C+i);
            X[i]++; Y[i]++;
            for (int l = X[i]; l < X[i]+L[i]; l++) for (int c = Y[i]; c < Y[i]+C[i]; c++)
                if (M[l][c]!=id) A++, M[l][c]=id;
        }

        for (int i = 0; i < N; i++) {
            for (int j = X[i]; j < X[i]+L[i]; j++) {
                int x = j, y = Y[i];
                if (M[x][y]!=id+1) {
                    M[x][y] = id+1;
                    int v = 0;
                    for (int k = 0; k < 4; k++) if (M[x+dx[k]][y+dy[k]]>=id) v++;
                    if (v == 3) P++;
                    else if (v == 2) P+=2;
                    else if (v == 1) P+=3;
                    else if (v == 0) P+=4;
                }

                x = j, y = Y[i]+C[i]-1;
                if (M[x][y]!=id+1) {
                    M[x][y] = id+1;
                    int v = 0;
                    for (int k = 0; k < 4; k++) if (M[x+dx[k]][y+dy[k]]>=id) v++;
                    if (v == 3) P++;
                    else if (v == 2) P+=2;
                    else if (v == 1) P+=3;
                    else if (v == 0) P+=4;
                }
            }
            for (int j = Y[i]+1; j < Y[i]+C[i]-1; j++) {
                int x = X[i], y = j;
                if (M[x][y]!=id+1) {
                    M[x][y] = id+1;
                    int v = 0;
                    for (int k = 0; k < 4; k++) if (M[x+dx[k]][y+dy[k]]>=id) v++;
                    if (v == 3) P++;
                    else if (v == 2) P+=2;
                    else if (v == 1) P+=3;
                    else if (v == 0) P+=4;
                }

                x = X[i]+L[i]-1, y = j;
                if (M[x][y]!=id+1) {
                    M[x][y] = id+1;
                    int v = 0;
                    for (int k = 0; k < 4; k++) if (M[x+dx[k]][y+dy[k]]>=id) v++;
                    if (v == 3) P++;
                    else if (v == 2) P+=2;
                    else if (v == 1) P+=3;
                    else if (v == 0) P+=4;
                }
            }
        }
        printf("%d %d\n", A, P);
        id+=2;
    }

    return 0;
}
