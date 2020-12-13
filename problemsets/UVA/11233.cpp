/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include <cctype>

using namespace std;

inline bool vogal(char c) {
    c = toupper(c);
    return c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}

int main() {

    int N, L;
    map<string, string> I;
    while (scanf("%d %d", &L, &N) != EOF) {
        char A[40], B[40];
        for (int i = 0; i < L; i++) scanf("%s %s", A, B), I[A] = B;
        for (int i = 0; i < N; i++) {
            scanf("%s", A);
            int N = strlen(A);
            if (I.count(A)) puts(I[A].c_str());
            else {
                if (N > 2 && !vogal(A[N-2]) && A[N-1]=='y') {
                    A[N-1] = 'i';
                    strcat(A, "es");
                }
                else if ( (N > 1 && A[N-1]=='o') ||
                          (N > 1 && A[N-1]=='s') ||
                          (N > 2 && A[N-2]=='s' && A[N-1]=='h') ||
                          (N > 2 && A[N-2]=='c' && A[N-1]=='h') ||
                          (N > 1 && A[N-1]=='x'))
                    strcat(A, "es");
                else strcat(A, "s");
                puts(A);
            }
        }
    }

    return 0;
}
