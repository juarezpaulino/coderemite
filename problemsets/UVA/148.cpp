/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> W;
char S[101], T[101];
int C[256];
int ret[2020], m;
vector<string> U;

vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}


void go(int k) {
    if (k == W.size()) {
        bool ok = 1;
        for (int i = 0; S[i]; i++) if (C[S[i]]) ok = 0;
        if (U.size() == m) {
            bool fail = 1;
            for (int i = 0; i < m; i++) if (U[i] != W[ret[i]]) fail = 0;
            if (fail) ok = 0;
        }
        if (ok) {
            printf("%s =", T);
            for (int i = 0; i < m; i++) printf(" %s", W[ret[i]].c_str());
            putchar('\n');
        }
        return;
    }
    bool ok = 1;
    for (int i = 0; W[k][i]; i++) {
        if (!C[W[k][i]]) ok = 0;
        C[W[k][i]]--;
    }
    if (ok) {
        ret[m++] = k;
        go(k+1);
        m--;
    }
    for (int i = 0; W[k][i]; i++) C[W[k][i]]++;
    go(k+1);
}

int main() {

    while (scanf("%s ", S)) {
        if (S == string("#")) break;
        W.push_back(S);
    }
    sort(W.begin(), W.end());
    while (gets(T)) {
        U = tokenize(T, " ");
        sort(U.begin(), U.end());
        int k = 0;
        for (int i = 0; T[i]; i++) if (T[i]!=' ') S[k++] = T[i];
        S[k] = 0;
        if (S == string("#")) break;
        for (int i = 'A'; i <= 'Z'; i++) C[i] = 0;
        for (int i = 0; S[i]; i++) C[S[i]]++;
        m = 0; go(0);
    }

    return 0;
}
