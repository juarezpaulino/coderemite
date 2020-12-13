/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main() {

    while (1) {

        int R[30] = {0}, nr = 0;
        char S[30] = {0};
        int f = 0, nb = 0;
        int ret = 0;
        int bonus = 0, cbonus = 0;

        while (1) {
            char c;
            scanf(" %c", &c);
            if (c == 'G') return 0;

            R[nr] = (c=='X') ? (S[nr]=2, 10) : (c=='/') ? (S[nr]=1, 10-R[nr-1]) : c-'0';
            nr++;

            nb++;
            if (c=='X' || nb==2) { f++; nb = 0; }
            if (bonus) cbonus--;

//            if (bonus && c=='/') cbonus++;
            if (!bonus && f == 10) bonus = nr, cbonus = (c=='X') ? 2 : (c=='/') ? 1 : 0;
            if (f >= 10 && !cbonus) break;
        }

        for (int i = 0; i < bonus; i++) {
            ret += R[i];
            if (S[i]) ret += R[i+1];
            if (S[i]==2) ret += R[i+2];
        }
        printf("%d\n", ret);
    }

    return 0;
}
