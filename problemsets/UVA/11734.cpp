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

using namespace std;

char A[30], B[30];

int main() {

    int T;
    gets(A);
    T = atoi(A);
    for (int t = 1; t <= T; t++) {
        gets(A); gets(B);
        printf("Case %d: ", t);
        if (!strcmp(A,B)) puts("Yes");
        else {
            int k = 0;
            for (int i = 0; A[i]; i++) if (!isspace(A[i])) A[k++] = A[i];
            A[k] = 0;
            k = 0;
            for (int i = 0; B[i]; i++) if (!isspace(B[i])) B[k++] = B[i];
            B[k] = 0;
            if (!strcmp(A,B)) puts("Output Format Error");
            else puts("Wrong Answer");
        }
    }

    return 0;
}
