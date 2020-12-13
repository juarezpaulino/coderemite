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

vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}


long long P[51][51];

int main() {

    for (int i = 0; i <= 50; i++) {
        P[i][0] = P[i][i] = 1;
        for (int j = 1; j < i; j++) P[i][j] = P[i-1][j-1] + P[i-1][j];
    }

    int T;
    char S[150];
    scanf("%d ", &T);
    for (int t = 1; t <= T; t++) {
        gets(S);
        vector<string> TOK = tokenize(S, "()+^");
        int K = atoi(TOK[2].c_str());
        printf("Case %d: ", t);
        for (int i = 0; i <= K; i++) {
            if (i > 0) printf("+");
            if (P[K][i] != 1) printf("%lld*", P[K][i]);
            if (K-i > 0) {
                printf("%s", TOK[0].c_str());
                if (K-i > 1) printf("^%d", K-i);
            }
            if (i > 0) {
                if (K-i > 0) printf("*");
                printf("%s", TOK[1].c_str());
                if (i > 1) printf("^%d", i);
            }
        }
        putchar('\n');
    }

    return 0;
}
