/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

using namespace std;

int main() {

    char S[110];
    int W, R, N;

    while (scanf("%s", S) != EOF) {
        W = R = 0; N = strlen(S);
        for (int i = 0; i < N; i++) {
            if (S[i]=='1') continue;
            R++;
            int j = i+1;
            if (!S[j]) j = 0;
            if (S[j]=='0') W++;
        }
        if (W*N > R*R) puts("SHOOT");
        else if (W*N < R*R) puts("ROTATE");
        else puts("EQUAL");
    }

    return 0;
}
