/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

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


int main() {

    char S[5000];
    int T; scanf("%d ", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:\n", t);
        while (gets(S)) {
            if (*S == 0) break;
            vector<string> tok = tokenize(S, " \t");
            string ret;
            int k = 0;
            for (int i = 0; i < tok.size(); i++) if (k < tok[i].size()) ret += tok[i][k++];
            printf("%s\n", ret.c_str());
        }
        if (t < T) putchar('\n');
    }

    return 0;
}
