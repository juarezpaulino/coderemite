/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <cctype>


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

    int T;
    scanf("%d", &T);
    while (T--) {
        int E, F;
        scanf("%d %d ", &E, &F);
        char S[1010];
        set<string> D;
        gets(S);
        for (int i = 0; S[i]; i++) S[i] = tolower(S[i]);
        vector<string> e = tokenize(S, " :-");
        for (int i = 0; i < e.size(); i++) D.insert(e[i]);
        for (int i = 0; i < F; i++) {
            gets(S);
            for (int i = 0; S[i]; i++) S[i] = tolower(S[i]);
            vector<string> e = tokenize(S, " :-");
            string ret;
            if (!D.count(e[0])) ret += toupper(e[0][0]);
            for (int i = 1; i < e.size(); i++) {
                if (D.count(e[i])) ret += e[i][0];
                else ret += toupper(e[i][0]);
            }
            printf("%s\n", ret.c_str());
        }
        putchar('\n');
    }

    return 0;
}
