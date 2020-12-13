/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

char S[10101];

vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int M;
        scanf("%d ", &M);
        vector<vector<string> > P;
        for (int i = 0; i < M; i++) {
            gets(S);
            vector<string> tok = tokenize(S, " ");
            P.push_back(tok);
        }
        int Y, X;
        scanf("%d %d", &X, &Y);
        bool found = 0;
        for (int k = 28; k >= 8; k--) {
            bool ok = 1;
            int i = 0, j = 0;
            for (int l = 0; ok && l < P.size(); l++) {
                for (int m = 0; ok && m < P[l].size(); m++) {
                    int c =  P[l][m].size();
//                    if (m < P[l].size()-1) c++;
                    j += c*k;
                    if (j > X) {
                        i += k; j = c*k;
                        if (j > X || i > Y) { ok = 0; continue; }
                    }
                    if (m < P[l].size()-1) {
                        j += k;
                        if (j > X) {
                            i += k; j = 0;
                            if (i > Y) { ok = 0; continue; }
                        }
                    }
                }
                i += k; j = 0;
                if (i > Y) { ok = 0; continue; }
            }
            if (ok) { found = 1; printf("%d\n", k); break; }
        }
        if (!found) puts("No solution");
    }

    return 0;
}
