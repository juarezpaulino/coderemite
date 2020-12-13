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
#include <queue>

using namespace std;

char A[100];

string M[4] = {
    "shata",
    "hajar",
    "lakh",
    "kuti"
};

int main() {

    int T = 1, N, i, j, k;
    while (scanf("%s", A) != EOF) {
        for (i = 0; A[i] && A[i]=='0'; i++);
        if (!A[i]) { printf("%4d. 0\n", T++); continue; }

        string S = A+i;
        string ret;
        N = S.size();
        if (N == 1 || N == 2) { printf("%4d. %s\n", T++, S.c_str()); continue; }

        ret = S.substr(N-2);
        while (ret.size()>1 && ret[0]=='0') ret = ret.substr(1);
        if (ret[0]=='0') ret = "";
        N-=2;

        k = 0;
        for (i = j = N; i > 0; ) {
            if (k == 0) {
                i--;
                if (S[i]!='0') ret = string(1, S[i]) + " " + M[k] + " " + ret;
            }
            else {
                i-=2;
                if (i < 0) i = 0;
                string s = S.substr(i,j-i);
                while (s.size()>1 && s[0]=='0') s = s.substr(1);
                if (s[0]=='0') s = "";
                if (!s.size()) {
                    if (k == 3) ret = M[k] + " " + ret;
                    goto END;
                }
                ret = s + " " + M[k] + " " + ret;
            }
END:
            k = (k+1) % 4;
            j = i;
        }
        N = ret.size()-1;
        while (ret[N]==' ') N--;
        ret = ret.substr(0,N+1);
        printf("%4d. %s\n", T++, ret.c_str());
    }

    return 0;
}
