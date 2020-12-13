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

int C[200];
int N;

inline int horner(int C[], int N, int x) {
    int ret = C[0];
    for (int i = 1; i < N; i++) ret = ret*x + C[i];
    return ret;
}


int main() {

    char S[1000];
    int x;
    while (gets(S)) {
        N = 0;
        {
            istringstream is(S);
            while (is >> x) {
                C[N++] = x;
            }
        }
        {
            gets(S);
            istringstream is(S);
            bool f = false;
            while (is >> x) {
                if (f) putchar(' ');
                f = true;
                printf("%d", horner(C,N,x));
            }
            putchar('\n');
        }
    }

    return 0;
}
