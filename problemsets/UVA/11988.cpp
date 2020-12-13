/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>

using namespace std;

char S[101010], A[202020], B[101010];

int main() {

    int b, e;
    while (gets(S)) {
        b = e = 101010;
        bool home = 1;
        int k = 0;
        for (int i = 0; S[i]; i++) {
            if (S[i] == '[' || S[i] == ']') {
                B[k] = 0;
                if (home) for (k = k-1; k >= 0; k--) A[--b] = B[k];
                else for (int j = 0; j < k; j++) A[e++] = B[j];
                home = (S[i]=='[') ? 1 : 0;
                k = 0;
            }
            else B[k++] = S[i];
        }
        B[k] = 0;
        if (home) for (k = k-1; k >= 0; k--) A[--b] = B[k];
        else for (int j = 0; j < k; j++) A[e++] = B[j];
        A[e] = 0;
        puts(A+b);
    }

    return 0;
}
