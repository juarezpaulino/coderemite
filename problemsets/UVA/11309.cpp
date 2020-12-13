/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        char S[20];
        int h, m;
        scanf("%d:%d", &h, &m);
        bool ok = 0;
        while (!ok) {
            m++;
            if (m >= 60) { h++; m = 0; }
            if (h >= 24) { h = 0;}
            if (h > 0) sprintf(S, "%d%02d", h, m);
            else sprintf(S, "%d", m);
            string s = S;
            bool pal = 1;
            int M = s.size();
            for (int i = 0; pal && i < M; i++) if (s[i]!=s[M-i-1]) pal = 0;
            if (pal) ok = 1;
        }
        printf("%02d:%02d\n", h, m);
    }

    return 0;
}
