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
#include <numeric>

using namespace std;



int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        char A[10], B[10], C[10];
        scanf("%s + %s = %s", A, B, C);
        bool ok = 1;
        for (int i = 0; ok && A[i]; i++) if (A[i] != '1') { ok = 0; break; }
        for (int i = 0; ok && B[i]; i++) if (B[i] != '1') { ok = 0; break; }
        for (int i = 0; ok && C[i]; i++) if (C[i] != '1') { ok = 0; break; }
        if (ok && string(A) + string(B) == string(C)) { puts("1"); continue; }
        int ret = -1;
        for (int b = 2; b <= 20; b++) {
            bool ok = 1;
            for (int i = 0; ok && A[i]; i++) if (A[i]-'0' >= b) { ok = 0; break; }
            for (int i = 0; ok && B[i]; i++) if (B[i]-'0' >= b) { ok = 0; break; }
            for (int i = 0; ok && C[i]; i++) if (C[i]-'0' >= b) { ok = 0; break; }
            if (!ok) continue;
            long long s = 0, x;
            x = 0;
            for (int i = 0; A[i]; i++) x = (x*b) + A[i]-'0'; s += x;
            x = 0;
            for (int i = 0; B[i]; i++) x = (x*b) + B[i]-'0'; s += x;
            x = 0;
            for (int i = 0; C[i]; i++) x = (x*b) + C[i]-'0'; s -= x;
            if (!s) { ret = b; break; }
        }
        if (ret == -1) puts("0");
        else printf("%d\n", ret);
    }

    return 0;
}
