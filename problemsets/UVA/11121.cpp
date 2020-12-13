/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        string ret;
        if (N != 0) while (N) {
            int r = N%-2;
            N /= -2;
            if (r < 0) { r = abs(r); N++; }
            ret = string(1,'0'+r) + ret;
        }
        else ret = "0";
        printf("Case #%d: %s\n", t, ret.c_str());
    }

    return 0;
}
