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

char A[100], B[100];
map<char,int> M;

int main() {

    for (int i = 0; i < 10; i++) M['0'+i] = i;
    for (int i = 'A'; i <= 'Z'; i++) M[i] = i-'A'+10;

    while (scanf("%s %s", A, B) != EOF) {
        int a, b;
        for (a = 2; a <= 36; a++) {
            bool f = true;
            for (int i = 0; A[i]; i++) if (M[A[i]] > a-1) { f = false; break; }
            if (!f) continue;
            for (b = 2; b <= 36; b++) {
                bool f = true;
                for (int i = 0; B[i]; i++) if (M[B[i]] > b-1) { f = false; break; }
                if (!f) continue;
                long long v1 = 0, v2 = 0;
                for (int i = 0; A[i]; i++) v1 = v1*a + M[A[i]];
                for (int i = 0; B[i]; i++) v2 = v2*b + M[B[i]];
                if (v1 == v2) goto OUT;
            }
        }
OUT:
        if (a==37) printf("%s is not equal to %s in any base 2..36\n", A, B);
        else printf("%s (base %d) = %s (base %d)\n", A, a, B, b);
    }

    return 0;
}
