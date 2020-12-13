/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {

    char R[10101];
    while (gets(R)) {
        int b = 0, s = 0;
        for (int i = 0; R[i]; i++) {
            int v = (R[i]>='0'&&R[i]<='9') ? R[i]-'0' : (R[i]>='A'&&R[i]<='Z') ? R[i]-'A'+10 : (R[i]>='a'&&R[i]<='z') ? R[i]-'a'+36 : 0;
            if (v > b) b = v;
            s += v;
        }
        if (s == 0) { puts("2"); continue; }
        int ret = -1;
        for (int k = b; k <= 61; k++) if (s % k == 0) { ret = k+1; break; }
        if (ret == -1) puts("such number is impossible!");
        else printf("%d\n", ret);
    }

    return 0;
}
